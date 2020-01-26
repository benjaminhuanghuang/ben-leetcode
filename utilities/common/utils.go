package common

import (
	"fmt"
	"io/ioutil"
	"os"
	"path"
	"regexp"
	"strings"
)

func CreateSolutionForProblem(problem ProblemItem) {
	solutionFolder, err := GenerateSolutionFolderName(problem)
	if err != nil {
		fmt.Printf("Can not create solution folder : %v", err)
		return
	}

	CreateGoSolution(solutionFolder, problem)
}

func CreateSolutionFolder(problem ProblemItem) (string, error) {
	folderName, err := GenerateSolutionFolderName(problem)
	if err != nil {
		return "", err
	}

	folderPath := path.Join(ROOT_PATH, folderName)
	_, err = os.Stat(folderPath)
	if os.IsExist(err) {
		fmt.Println(folderPath + "is existed.")
		return "", err
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
func GenerateSolutionFolderName(problem ProblemItem) (string, error) {
	var title = strings.TrimSpace(problem.Title)
	space := regexp.MustCompile(`\s+`)
	title = space.ReplaceAllString(title, "_")
	return fmt.Sprintf("%04d_%s", problem.Number, title), nil
}

func CreateGoSolution(solutionFolder string, problem ProblemItem) {
	tempalteFile := path.Join(ROOT_PATH, "code_keleton", "go", "solution.go")
	destinationFile := path.Join(solutionFolder, "solution.go")
	GenerateGoSolutionFile(tempalteFile, destinationFile, problem)

	tempalteFile = path.Join(ROOT_PATH, "code_keleton", "go", "solution_test.go")
	destinationFile = path.Join(solutionFolder, "solution_test.go")
	GenerateGoSolutionFile(tempalteFile, destinationFile, problem)
}

/*
	Generate solution file
	1. Copy code template to destination
	2. Generate some file content
*/
func GenerateGoSolutionFile(sourceFile string, destinationFile string, problem ProblemItem) {
	_, err := os.Stat(destinationFile)
	if os.IsExist(err) {
		fmt.Printf("File %s is existed \n", destinationFile)
		return
	}
	input, readErr := ioutil.ReadFile(sourceFile)
	if readErr != nil {
		fmt.Printf("Can not read file %s : %v: \n", sourceFile, readErr)
		return
	}
	const LEETCODE_URL = "https://leetcode.com"
	// Add url and package name
	lines := strings.Split(string(input), "\n")
	lines[0] = fmt.Sprintf("// %s%s", LEETCODE_URL, problem.Url)
	lines[1] = "package leetcode" + strings.Split(destinationFile, "_")[0]
	output := strings.Join(lines, "\n")

	err = ioutil.WriteFile(destinationFile, []byte(output), 0666)
	if err != nil {
		fmt.Printf("Can not write file %s : %v \n", destinationFile, err)
		return
	}
}
