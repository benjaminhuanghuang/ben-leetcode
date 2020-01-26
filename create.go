package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"path"
	"regexp"
	"strconv"
	"strings"

	"github.com/PuerkitoBio/goquery"
)

type ProblemItem struct {
	number int
	title  string
	url    string
}

// Url: https://leetcode.com/problemset/all/

const LEETCODE_URL = "https://leetcode.com"

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
			createSourceFile(ProblemItem{
				number,
				title,
				url,
			})
		}
	})
}

func createSourceFile(problem ProblemItem) {
	folderName, err := createFolderName(problem)
	if err != nil {
		fmt.Printf("Can not creat folder: %v", err)
		return
	}
	fmt.Println(">> Create solution: " + folderName)
	_, err = os.Stat(folderName)

	if os.IsNotExist(err) {
		err = os.Mkdir(folderName, os.ModePerm)
		if err != nil {
			fmt.Printf("Can not creat folder: %v", err)
			return
		}
	}
	createSourceFiles(folderName, problem)
}

func createFolderName(problem ProblemItem) (string, error) {
	var title = strings.TrimSpace(problem.title)
	space := regexp.MustCompile(`\s+`)
	title = space.ReplaceAllString(title, "_")
	return fmt.Sprintf("%04d_%s", problem.number, title), nil
}

func createSourceFiles(folder string, problem ProblemItem) {
	sourceFile := path.Join("0000_Problem", "solution.go")
	destinationFile := path.Join(folder, "solution.go")
	copyFile(sourceFile, destinationFile, problem)

	sourceFile = path.Join("0000_Problem", "solution_test.go")
	destinationFile = path.Join(folder, "solution_test.go")
	copyFile(sourceFile, destinationFile, problem)
}

func copyFile(sourceFile string, destinationFile string, problem ProblemItem) {
	_, err := os.Stat(destinationFile)
	if os.IsNotExist(err) {
		input, readErr := ioutil.ReadFile(sourceFile)
		if readErr != nil {
			fmt.Printf("Can not read file %s : %v: \n", sourceFile, readErr)
			return
		}

		lines := strings.Split(string(input), "\n")
		lines[0] = fmt.Sprintf("// %s%s", LEETCODE_URL, problem.url)
		lines[1] = "package leetcode" + strings.Split(destinationFile, "_")[0]
		output := strings.Join(lines, "\n")

		err = ioutil.WriteFile(destinationFile, []byte(output), 0666)
		if err != nil {
			fmt.Printf("Can not write file %s : %v \n", destinationFile, err)
			return
		}
	} else {
		fmt.Printf("File %s is existed \n", destinationFile)
	}
}
