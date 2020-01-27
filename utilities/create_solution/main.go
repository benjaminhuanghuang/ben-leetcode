package main

import (
	"fmt"
	. "../common"
)

func main() {
	problemIds := []int{1322}
	for _, id := range problemIds {
		p, err := GetProblemInfoById(id)
		if err == nil {
			CreateSolutionForProblem(p)
		}
	}
}