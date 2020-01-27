package common

import (
	"fmt"
	"testing"
	// "github.com/stretchr/testify/assert"
)

func test_CreateSolutionForProblem(t *testing.T) {
	problem := LeetCodeProblem{
		ID:    1332,
		Title: "Remove Palindromic Subsequences",
		Url:   "https://leetcode.com/problems/remove-palindromic-subsequences/",
	}

	CreateSolutionForProblem(problem)
}

func Test_GetProblemInfo(t *testing.T) {
	p, _ := GetProblemInfo()

	fmt.Print(p)
}

func Test_GetAllProblemJson(t *testing.T) {
	p, _ := GetAllProblemsInfo()

	fmt.Println(len(p))
}
