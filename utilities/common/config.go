package common

const LEETCODE_URL = "https://leetcode.com"
const LEETCODE_PROBLEMS_BASE_URL = "https://leetcode.com/problems/"
const LEETCODE_PROBLEMS_API_URL = "https://leetcode.com/api/problems/algorithms/"
const LEETCODE_GRPAHQL_API_URL = "https://leetcode.com/graphql"

const ROOT_PATH = "/Users/bhuang/ben-github/ben-leetcode/"

var SETTINGS = []LanguageSetting{
	{
		"go",
		"solution.go",
		"solution_test.go",
		map[string]string{"{REPLACE_1}": "PROBLEM_NUMBER"},
	},
	{
		"cpp",
		"solution.cpp",
		"solution_test.cpp",
		map[string]string{},
	},
	{
		"js",
		"solution.js",
		"solution.spec.js",
		map[string]string{},
	},
	{
		"py",
		"solution.py",
		"solution_test.py",
		map[string]string{},
	},
	{
		"java",
		"solution.java",
		"solution_test.java",
		map[string]string{},
	},
}
