package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"path"
	"strconv"
	"strings"

	"github.com/PuerkitoBio/goquery"

	. "../common"
)



func main() {
	problemIds := []int{1111, 222, 222}
	for _, id := range problemIds{
		p , err := GetProblemInfoById(id)
		if err == nil
		{
			problem := LeetCodeProblem {
				Stat: LeetCodeProblemStat {
					ID:    p.,
					Title: "Remove Palindromic Subsequences",
					TitleSlug:   "remove-palindromic-subsequences",
				}
			}
		
			CreateSolutionForProblem(problem)
		}
	}
	
}


