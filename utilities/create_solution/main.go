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


func login(name string, pwd string):
    login_url = ''

    if name is not None and pwd is not None:
        client.get(login_url)
        csrftoken = client.cookies['csrftoken']

        data = dict(
            login=NAME,
            password=PASSWORD,
            csrfmiddlewaretoken=csrftoken)
        headers = dict(Referer=login_url)

        login_response = client.post(login_url, data=data, headers=headers)
        if login_response.status_code == 200:
            print('Login success.')
            return 200
    print('Login failed.')
		return None




func main() {
	url := "https://leetcode.com/problems/remove-palindromic-subsequences/"
	p , err := GetProblemInfo(url)
	if err == nil
	{
		problem := ProblemItem{
			Number: 1332,
			Title:  "Remove Palindromic Subsequences",
			Level:  "Easy",
			Url:    "https://leetcode.com/problems/remove-palindromic-subsequences/",
		}
	
		CreateSolutionForProblem(problem)
	}
}


