package common

import (
	"bytes"
	"encoding/json"
	"errors"
	"fmt"
	"io/ioutil"
	"net/http"
)

/*
GetAllProblemsInfo calls https://leetcode.com/api/problems/algorithms/ and returns a ploblem list
*/
func GetAllProblems() ([]LeetCodeProblem, error) {
	response, err := http.Get(LEETCODE_PROBLEMS_API_URL)

	if err != nil {
		return nil, err
	}

	jsonBody, err := ioutil.ReadAll(response.Body)
	if err != nil {
		return nil, err
	}
	// fmt.Printf("%s", jsonBody)
	var responseObject LeetCodeProblemsAPIResponse
	json.Unmarshal(jsonBody, &responseObject)
	return responseObject.Problems, nil
}

/*
GetProblemDetailBySlug calls Leetcode GraphQL API https://leetcode.com/graphql to get problem detail by title slug
*/
func GetProblemDetailBySlug(titleSlug string) (LeetCodeProblemDetail, error) {
	payload := fmt.Sprintf(`{
		"operationName": "questionData",
		"variables": {
			"titleSlug": "%s"
		},
		"query": "query questionData($titleSlug: String!) {question(titleSlug: $titleSlug) {questionId  questionFrontendId title titleSlug difficulty content codeSnippets{      lang      langSlug   code   }}}"
	}`, titleSlug)

	req, err := http.NewRequest("POST", LEETCODE_GRPAHQL_API_URL, bytes.NewBuffer([]byte(payload)))
	req.Header.Set("Content-type", "application/json")
	if err != nil {
		return LeetCodeProblemDetail{}, err
	}
	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		panic(err)
	}
	jsonBody, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return LeetCodeProblemDetail{}, err
	}
	// fmt.Printf("%s", jsonBody)
	var responseObject LeetCodeProblemDetailAPIResponse
	json.Unmarshal(jsonBody, &responseObject)
	return responseObject.Data.Question, nil
}

/*
GetProblemDetailByFrontendId calls Leetcode GraphQL API https://leetcode.com/graphql to get problem detail by title slug
*/
func GetProblemDetailByFrontendId(Id int) (LeetCodeProblemDetail, error) {
	problems, _ := GetAllProblems()
	for _, p := range problems {
		if p.Stat.FrontendID == Id {
			return GetProblemDetailBySlug(p.Stat.TitleSlug)
		}
	}
	return LeetCodeProblemDetail{}, errors.New("Can not find problem")
}
