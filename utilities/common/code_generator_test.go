package common

import (
	"testing"
	// "github.com/stretchr/testify/assert"
)

func Test_CreateSolutionForProblem(t *testing.T) {
	problem := LeetCodeProblemDetail{
		FrontendID:   "1332",
		Title:        "Remove Palindromic Subsequences",
		TitleSlug:    "remove-palindromic-subsequences",
		Difficulty:   "Easy",
		CodeSnippets: []LeetCodeCodeSnippet{},
	}
	CreateSolutionForProblem(problem)
}

func Test_CreateSolution(t *testing.T) {
	id := 234
	p, _ := GetProblemDetailByFrontendId(id)
	CreateSolutionForProblem(p)
}
