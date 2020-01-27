package common

import (
	"bytes"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"path"
	"regexp"
	"strings"
)

func GetAllProblemsInfo() ([]LeetCodeProblem, error) {
	response, err := http.Get(LEETCODE_PROBLEMS_API_URL)

	if err != nil {
		return nil, err
	}

	jsonBody, err := ioutil.ReadAll(response.Body)
	if err != nil {
		return nil, err
	}
	// fmt.Printf("%s", jsonBody)
	var responseObject APIResponse
	json.Unmarshal(jsonBody, &responseObject)
	return responseObject.Problems, nil
}

func GetProblemInfoBySlug() (LeetCodeProblem, error) {
	titleSlug := "two-sum"
	body := fmt.Sprintf(`"operationName": "questionData",
												"variables": {
													"titleSlug": %s
												},
  											"query": "query questionData($titleSlug: String!) {question(titleSlug: $titleSlug) {
														questionId
														questionFrontendId
														titleSlug
														codeSnippets{
															lang
															langSlug
															code
														}
													}
												}
											}`, titleSlug)
	req, err := http.NewRequest("POST", "https://leetcode.com/graphql", bytes.NewBuffer([]byte(body)))
	if err != nil {
		return LeetCodeProblem{}, err
	}
	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		panic(err)
	}

	fmt.Println(">>>> response Status:", resp.Status)
	fmt.Println(">>>> response Headers:", resp.Header)
	p, _ := ioutil.ReadAll(resp.Body)
	fmt.Printf("%s", p)
	return LeetCodeProblem{}, nil
}

func CreateSolutionForProblem(problem LeetCodeProblem) {
	solutionFolder, err := CreateSolutionFolder(problem)
	if err != nil {
		fmt.Printf("Can not create solution folder : %v", err)
		return
	}

	for _, setting := range SETTINGS {
		fmt.Println("Create solution for " + setting.FileExtension)
		CreateSolution(solutionFolder, problem, setting)
	}
}

func CreateSolutionFolder(problem LeetCodeProblem) (string, error) {
	folderName := GenerateSolutionFolderName(problem)

	folderPath := path.Join(ROOT_PATH, folderName)
	_, err := os.Stat(folderPath)
	if err == nil {
		fmt.Println(folderPath + "is existed.")
		return folderPath, nil
	}

	err = os.Mkdir(folderPath, os.ModePerm)
	if err != nil {
		fmt.Printf("Can not creat folder %s: %v", folderPath, err)
		return "", err
	}
	fmt.Println(folderPath + "is ceated")
	return folderPath, nil
}

/*
	GenerateSolutionFolderName creates solution folder name based on problem id and problem title
	1  -> 0001_problem_1
*/
func GenerateSolutionFolderName(problem LeetCodeProblem) string {
	var title = strings.TrimSpace(problem.Stat.Title)
	space := regexp.MustCompile(`\s+`)
	title = space.ReplaceAllString(title, "_")
	return fmt.Sprintf("%04d_%s", problem.Stat.ID, title)
}

func CreateSolution(solutionFolder string, problem LeetCodeProblem, setting LanguageSetting) {
	solutionTempalteFile := path.Join(ROOT_PATH, "code_skeleton", setting.FileExtension, setting.SolutionFileName)
	destinationFile := path.Join(solutionFolder, setting.SolutionFileName)
	GenerateSolutionFile(solutionTempalteFile, destinationFile, problem, setting)

	testTempalteFile := path.Join(ROOT_PATH, "code_skeleton", setting.FileExtension, setting.TestFileName)
	destinationFile = path.Join(solutionFolder, setting.TestFileName)
	GenerateSolutionFile(testTempalteFile, destinationFile, problem, setting)
}

/*
	Generate solution file
	1. Copy code template to destination
	2. Generate some file content
*/
func GenerateSolutionFile(sourceFile string, destinationFile string, problem LeetCodeProblem, setting LanguageSetting) {
	_, err := os.Stat(destinationFile)
	if err == nil {
		fmt.Printf("File %s is existed \n", destinationFile)
		return
	}
	input, readErr := ioutil.ReadFile(sourceFile)
	if readErr != nil {
		fmt.Printf("Can not read file %s : %v: \n", sourceFile, readErr)
		return
	}

	// Add title
	fileContent := strings.Replace(string(input), "{TITLE}", fmt.Sprintf("%04d. %s", problem.Stat.ID, problem.Stat.Title), 1)
	// Add yrl
	fileContent = strings.Replace(fileContent, "{URL}", LEETCODE_PROBLEMS_BASE_URL+problem.Stat.TitleSlug, 1)

	// Replace
	for k, v := range setting.Replaces {
		fileContent = strings.Replace(fileContent, k, createReplaceString(v, problem), 1)
	}

	err = ioutil.WriteFile(destinationFile, []byte(fileContent), 0666)
	if err != nil {
		fmt.Printf("Can not write file %s : %v \n", destinationFile, err)
		return
	}
}

func createReplaceString(name string, problem LeetCodeProblem) string {
	switch name {
	case "PROBLEM_NUMBER":
		return fmt.Sprintf("%04d", problem.Stat.ID)
	default:
		return ""
	}
}
