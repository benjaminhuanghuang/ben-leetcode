package main

import (
	. "../common"
	"fmt"
)

func main() {
	problemIds := []int{1385}
	for _, id := range problemIds {
		p, err := GetProblemDetailByFrontendId(id)
		if err != nil {
			fmt.Printf("%v\n", err)
		}
		fmt.Println("Craete solution for ", p.Title)
		CreateSolutionForProblem(p)
	}
}
