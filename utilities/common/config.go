package common

const LEETCODE_URL = "https://leetcode.com"
const LEETCODE_PROBLEMS_BASE_URL = "https://leetcode.com/problems/"
const LEETCODE_PROBLEMS_API_URL = "https://leetcode.com/api/problems/algorithms/"
const LEETCODE_GRPAHQL_API_URL = "https://leetcode.com/graphql"

const ROOT_PATH = "/Users/bhuang/ben-github/ben-leetcode/"

var SETTINGS = []LanguageSetting{
	{
		"Go",
		"go",
		"solution.go",
		"solution_test.go",
		map[string]string{"{REPLACE_1}": "PROBLEM_NUMBER"},
	},
	{
		"C++",
		"cpp",
		"solution.cpp",
		"solution_test.cpp",
		map[string]string{},
	},
	{
		"JavaScript",
		"js",
		"solution.js",
		"solution.spec.js",
		map[string]string{},
	},
	{
		"Python3",
		"py",
		"solution.py",
		"solution_test.py",
		map[string]string{},
	},
	{
		"Java",
		"java",
		"solution.java",
		"solution_test.java",
		map[string]string{},
	},
}
