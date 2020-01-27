package common

const LEETCODE_URL = "https://leetcode.com"

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
		"solution.py",
		"solution_test.py",
		map[string]string{},
	},
}
