package main

import (
	"fmt"
	. "../common"
)

func main() {
	// problemIds := []int{1322}
	// for _, id := range problemIds {
	// 	p, err := GetProblemInfoById(id)
	// 	if err == nil {
	// 		CreateSolutionForProblem(p)
	// 	}
	// }

	p, err := GetProblemInfoBySlug("minimum-difficulty-of-a-job-schedule")
	if err == nil {
		CreateSolutionForProblem(p)
	}

}
