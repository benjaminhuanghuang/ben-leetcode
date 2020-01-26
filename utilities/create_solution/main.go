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

// Url: https://leetcode.com/problemset/all/

func main() {
	home, err := os.UserHomeDir()
	if err != nil {
		log.Fatal(err)
		return
	}
	filePath := path.Join(home, "Desktop", "leetcode.html")
	// filePath := "./leetcode.html"

	contents, err := ioutil.ReadFile(filePath)
	if err != nil {
		fmt.Printf("Can not read file: %v", err)
		return
	}
	// Load the HTML document
	doc, err := goquery.NewDocumentFromReader(strings.NewReader(string(contents)))
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(doc)
	//---------------------------------
	start, end := 21, 30
	doc.Find("tbody.reactable-data>tr").Each(func(i int, tr *goquery.Selection) {
		// fmt.Println("Process tr....")
		var number int
		var title string
		var url string
		tr.Find("td").Each(func(i int, td *goquery.Selection) {
			if i == 1 {
				number, err = strconv.Atoi(td.Text())
				if err != nil {
					return
				}
			} else if i == 2 {
				title = td.Find("a").Text()
				url, _ = td.Find("a").Attr("href")
			}
		})
		// fmt.Printf("number: %s, title: %v \n", number, title)
		if number >= start && number <= end {
			CreateSolutionForProblem(ProblemItem{
				Number:number,
				Title:title,
				Url:url,
			})
		}
	})
}


