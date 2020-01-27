package common

import (
	"fmt"
	"io/ioutil"
	"os"
	"path"
	"regexp"
	"strings"
)

func GetProblemInfo(url string) ProblemItem {
	p := ProblemItem{}
	return p
}

func CreateSolutionForProblem(problem ProblemItem) {
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

func CreateSolutionFolder(problem ProblemItem) (string, error) {
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
	GenerateSolutionFolderName creates solution folder name based on problem number and problem number
	1  -> 0001_problem_1
*/
func GenerateSolutionFolderName(problem ProblemItem) string {
	var title = strings.TrimSpace(problem.Title)
	space := regexp.MustCompile(`\s+`)
	title = space.ReplaceAllString(title, "_")
	return fmt.Sprintf("%04d_%s", problem.Number, title)
}

func CreateSolution(solutionFolder string, problem ProblemItem, setting LanguageSetting) {
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
func GenerateSolutionFile(sourceFile string, destinationFile string, problem ProblemItem, setting LanguageSetting) {
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
	fileContent := strings.Replace(string(input), "{TITLE}", fmt.Sprintf("%04d. %s", problem.Number, problem.Title), 1)
	// Add yrl
	fileContent = strings.Replace(fileContent, "{URL}", problem.Url, 1)

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

func createReplaceString(name string, problem ProblemItem) string {
	switch name {
	case "PROBLEM_NUMBER":
		return fmt.Sprintf("%04d", problem.Number)
	default:
		return ""
	}
}
