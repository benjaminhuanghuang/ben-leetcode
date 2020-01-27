package common

const LEETCODE_URL = "https://leetcode.com"
const LEETCODE_PROBLEMS_BASE_URL = "https://leetcode.com/problems/"
const LEETCODE_PROBLEMS_API_URL = "https://leetcode.com/api/problems/algorithms/"
const LEETCODE_GRPAHQL_API_URL = "https://leetcode.com/graphql"

const ROOT_PATH = "/Users/bhuang/ben-github/ben-leetcode/"

type LanguageSetting struct {
	Language         string // should match the name with Leetcode
	FileExtension    string // can be used as folder name of template files
	SolutionFileName string
	TestFileName     string
	NeedTest         bool
	Replaces         map[string]string
}

var SETTINGS = []LanguageSetting{
	{
		"Go",
		"go",
		"solution.go",
		"solution_test.go",
		true,
		map[string]string{"{REPLACE_1}": "PROBLEM_ID"},
	},
	{
		"C++",
		"cpp",
		"solution.cpp",
		"solution_test.cpp",
		false,
		map[string]string{},
	},
	{
		"JavaScript",
		"js",
		"solution.js",
		"solution.spec.js",
		true,
		map[string]string{},
	},
	{
		"Python3",
		"py",
		"solution.py",
		"solution_test.py",
		true,
		map[string]string{},
	},
	{
		"Java",
		"java",
		"solution.java",
		"solution_test.java",
		false,
		map[string]string{},
	},
}
