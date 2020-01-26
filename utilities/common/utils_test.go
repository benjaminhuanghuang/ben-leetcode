package common

import (
	"testing"
)

func Test_OK(t *testing.T) {
	problem := ProblemItem{
		Number: 1332,
		Title:  "Remove Palindromic Subsequences",
		Level:  "Easy",
		Url:    "https://leetcode.com/problems/remove-palindromic-subsequences/",
	}

	CreateSolutionForProblem(problem)
}
