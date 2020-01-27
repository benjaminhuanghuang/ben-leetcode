package main

import (
	. "../common"
)

func main() {
	problems, err := GetAllProblemsInfo()
	if err == nil {
		for _, p := range problems {
			CreateSolutionForProblem(p)
		}
	}
}
