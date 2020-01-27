package common

import (
	"github.com/stretchr/testify/assert"
	"strconv"
	"testing"
)

func Test_GetAllProblemInfo(t *testing.T) {
	problems, _ := GetAllProblems()

	// fmt.Println(len(p))
	assert.Greater(t, 1000, len(problems))
}

func Test_GetProblemDetailBySlug(t *testing.T) {
	titleSlug := "minimum-difficulty-of-a-job-schedule"
	id := 1335
	p, _ := GetProblemDetailBySlug(titleSlug)

	// fmt.Printf("%v\n", p)
	assert.Equal(t, titleSlug, p.TitleSlug)
	assert.Equal(t, id, p.ID)
}

func Test_GetProblemDetailById(t *testing.T) {
	id := 1335
	titleSlug := "minimum-difficulty-of-a-job-schedule"
	p, _ := GetProblemDetailByFrontendId(1335)

	// fmt.Printf("%v\n", p)
	assert.Equal(t, strconv.Itoa(id), p.FrontendID)
	assert.Equal(t, titleSlug, p.TitleSlug)
}
