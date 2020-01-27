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


func Test_GetAllProblemInfo(t *testing.T) {
	p, _ := GetAllProblemsInfo()

	fmt.Println(len(p))
}

func Test_GetProblemInfoBySlug(t *testing.T) {
	p, _ := GetProblemInfoBySlug("minimum-difficulty-of-a-job-schedule")

	fmt.Printf("%v\n",p)
}

func Test_GetProblemInfoById(t *testing.T) {
	p, _ := GetProblemInfoById(1335)

	fmt.Printf("%v\n",p)
}
