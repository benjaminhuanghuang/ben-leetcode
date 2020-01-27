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

func GetProblemInfoBySlug(titleSlug string) (LeetCodeProblemDetail, error) {
	payload := fmt.Sprintf(`{
		"operationName": "questionData",
		"variables": {
			"titleSlug": "%s"
		},
		"query": "query questionData($titleSlug: String!) {question(titleSlug: $titleSlug) {questionId   questionFrontendId title titleSlug codeSnippets{      lang      langSlug   code   }}}"
	}`, titleSlug)

	req, err := http.NewRequest("POST", LEETCODE_GRPAHQL_API_URL, bytes.NewBuffer([]byte(payload)))
	req.Header.Set("Content-type", "application/json")
	if err != nil {
		return LeetCodeProblemDetail{}, err
	}
	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		panic(err)
	}
	jsonBody, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return LeetCodeProblemDetail{}, err
	}
	// fmt.Printf("%s", jsonBody)
	var responseObject LeetCodeProblemDetailAPIResponse
	json.Unmarshal(jsonBody, &responseObject)
	return responseObject.Data.Question, nil
}

func GetProblemInfoById(Id int) (LeetCodeProblemDetail, error) {
	payload := fmt.Sprintf(`{
		"operationName": "questionData",
		"variables": {
			"titleSlug": "%s"
		},
		"query": "query questionData($titleSlug: String!) {question(titleSlug: $titleSlug) {questionId   questionFrontendId title titleSlug codeSnippets{      lang      langSlug   code   }}}"
	}`, Id)

	req, err := http.NewRequest("POST", LEETCODE_GRPAHQL_API_URL, bytes.NewBuffer([]byte(payload)))
	req.Header.Set("Content-type", "application/json")
	if err != nil {
		return LeetCodeProblemDetail{}, err
	}
	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		panic(err)
	}
	jsonBody, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return LeetCodeProblemDetail{}, err
	}
	// fmt.Printf("%s", jsonBody)
	var responseObject LeetCodeProblemDetailAPIResponse
	json.Unmarshal(jsonBody, &responseObject)
	return responseObject.Data.Question, nil
}

func CreateSolutionForProblem(problem LeetCodeProblemDetail) {
	solutionFolder, err := CreateSolutionFolder(problem)
	if err != nil {
		fmt.Printf("Can not create solution folder : %v", err)
		return
	}

	for _, setting := range SETTINGS {
		// fmt.Println("Create solution for " + setting.FileExtension)
		CreateSolution(solutionFolder, problem, setting)
	}
}

func CreateSolutionFolder(problem LeetCodeProblemDetail) (string, error) {
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
func GenerateSolutionFolderName(problem LeetCodeProblemDetail) string {
	var title = strings.TrimSpace(problem.Title)
	space := regexp.MustCompile(`\s+`)
	title = space.ReplaceAllString(title, "_")
	return fmt.Sprintf("%04d_%s", problem.ID, title)
}

func CreateSolution(solutionFolder string, problem LeetCodeProblemDetail, setting LanguageSetting) {
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
func GenerateSolutionFile(sourceFile string, destinationFile string, problem LeetCodeProblemDetail, setting LanguageSetting) {
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
	fileContent := strings.Replace(string(input), "{TITLE}", fmt.Sprintf("%04d. %s", problem.ID, problem.Stat.Title), 1)
	// Add yrl
	fileContent = strings.Replace(fileContent, "{URL}", LEETCODE_PROBLEMS_BASE_URL+problem.TitleSlug, 1)

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

func createReplaceString(name string, problem LeetCodeProblemDetail) string {
	switch name {
	case "PROBLEM_NUMBER":
		return fmt.Sprintf("%04d", problem.ID)
	case "PROBLEM_LEVEL":
		return problem.Difficulty
	default:
		return ""
	}
}
