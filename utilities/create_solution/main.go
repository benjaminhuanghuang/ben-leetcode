package main

import (
	"fmt"

	. "../common"
)

func main() {
	problemIds := []int{973}
	for _, id := range problemIds {
		p, err := GetProblemDetailByFrontendId(id)
		if err != nil {
			fmt.Printf("%v\n", err)
			return
		}
		fmt.Println("Create solution for ", p.Title)
		CreateSolutionForProblem(p)
	}
}
