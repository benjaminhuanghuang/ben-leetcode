package main

import (
	"fmt"

	. "../common"
)

func main() {
	problemIds := []int{1189}
	for _, id := range problemIds {
		p, err := GetProblemDetailByFrontendId(id)
		if err != nil {
			fmt.Printf("%v\n", err)
		}
		fmt.Println("Craete solution for ", p.Title)
		CreateSolutionForProblem(p)
	}
}
