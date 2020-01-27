package common

import (
	"fmt"
	"io/ioutil"
	"os"
	"path"
	"regexp"
	"strconv"
	"strings"
)

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
	return fmt.Sprintf("%s_%s", formatProblemID(problem.FrontendID), title)
}

func CreateSolution(solutionFolder string, problem LeetCodeProblemDetail, setting LanguageSetting) {
	solutionTempalteFile := path.Join(ROOT_PATH, "code_skeleton", setting.FileExtension, setting.SolutionFileName)
	destinationFile := path.Join(solutionFolder, setting.SolutionFileName)
	GenerateSolutionFile(solutionTempalteFile, destinationFile, problem, setting)
	if setting.NeedTest {
		testTempalteFile := path.Join(ROOT_PATH, "code_skeleton", setting.FileExtension, setting.TestFileName)
		destinationFile = path.Join(solutionFolder, setting.TestFileName)
		GenerateSolutionFile(testTempalteFile, destinationFile, problem, setting)
	}
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
	fileContent := strings.Replace(string(input), "{TITLE}", fmt.Sprintf("%s. %s", problem.FrontendID, problem.Title), 1)
	// Add yrl
	fileContent = strings.Replace(fileContent, "{URL}", LEETCODE_PROBLEMS_BASE_URL+problem.TitleSlug, 1)
	// Level
	fileContent = strings.Replace(fileContent, "{LEVEL}", problem.Difficulty, 1)

	// Replace
	for k, v := range setting.Replaces {
		fileContent = strings.Replace(fileContent, k, createReplaceString(v, problem), 1)
	}
	// Code
	for _, codeSnippet := range problem.CodeSnippets {
		if codeSnippet.Language == setting.Language {
			fileContent = strings.Replace(fileContent, "{CODE}", codeSnippet.Code, 1)
			break
		}
	}

	err = ioutil.WriteFile(destinationFile, []byte(fileContent), 0666)
	if err != nil {
		fmt.Printf("Can not write file %s : %v \n", destinationFile, err)
		return
	}
}

func formatProblemID(id string) string {
	num, _ := strconv.Atoi(id)
	return fmt.Sprintf("%04d", num)
}

func createReplaceString(name string, problem LeetCodeProblemDetail) string {
	switch name {
	case "PROBLEM_ID":
		return formatProblemID(problem.FrontendID)
	default:
		return ""
	}
}
