package common

import (
	"fmt"
	"testing"
	// "github.com/stretchr/testify/assert"
)

func Test_CreateSolutionForProblem(t *testing.T) {
	problem := LeetCodeProblemDetail {
		ID:    "1332",
		Title: "Remove Palindromic Subsequences",
		TitleSlug:   "remove-palindromic-subsequences",
		Difficulty: "Easy",
	}
	CreateSolutionForProblem(problem)
}


