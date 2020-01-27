package common

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_CreateSolutionForProblem(t *testing.T) {
	problem := ProblemItem{
		Number: 1332,
		Title:  "Remove Palindromic Subsequences",
		Level:  "Easy",
		Url:    "https://leetcode.com/problems/remove-palindromic-subsequences/",
	}

	CreateSolutionForProblem(problem)
}

func test_GetProblemInfo(t *testing.T) {
	url := "https://leetcode.com/problems/remove-palindromic-subsequences/"
	p := GetProblemInfo(url)

	assert.Equal(t, 1332, p.Number)
	assert.Equal(t, "Remove Palindromic Subsequences", p.Title)
	assert.Equal(t, url, url)
}
