package main

import (
	"fmt"

	. "../common"
)

func main() {
	problems, err := GetAllProblemsInfo()
	if err == nil {
		for _, p := range problems {
			fmt.Printf("%v\n", p)
			//CreateSolutionForProblem(p)
		}
	}
}
