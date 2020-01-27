package common

import (
	"fmt"
	"testing"
	// "github.com/stretchr/testify/assert"
)

func Test_CreateSolutionForProblem(t *testing.T) {
	problem := LeetCodeProblem {
		Stat: LeetCodeProblemStat {
			ID:    1332,
			Title: "Remove Palindromic Subsequences",
			TitleSlug:   "remove-palindromic-subsequences",
		},
		Difficulty: LeetCodeProblemDifficulty{
			Level : 1,
		},
	}
	CreateSolutionForProblem(problem)
}


func Test_GetAllProblemInfo(t *testing.T) {
	p, _ := GetAllProblemsInfo()

	fmt.Println(len(p))
}

func Test_GetProblemInfoBySlug(t *testing.T) {
	p, _ := GetProblemInfoBySlug()

	fmt.Print(p)
}

func Test_GetProblemInfoBySlug(t *testing.T) {
	p, _ := GetProblemInfoBySlug()

	fmt.Print(p)
}
