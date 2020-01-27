package common

type APIResponse struct {
	Problems []LeetCodeProblem `json:"stat_status_pairs"`
}

type LeetCodeProblem struct {
	Stat LeetCodeProblemStat `json:"stat"`
	Difficulty LeetCodeProblemDifficulty`json:"difficulty"`
	PaidOnly bool`json:"paid_only"`
	IsFavor bool `json:"is_favor"`
}

type LeetCodeProblemStat struct {
	ID int           `json:"question_id"`
	Title string     `json:"question__title"`
	TitleSlug string `json:"question__title_slug"`
	IsNew bool       `json:"is_new_question"`
}

type LeetCodeProblemDifficulty struct {
	Level int`json:"level"`
}

type LanguageSetting struct {
	Language         string
	FileExtension    string
	SolutionFileName string
	TestFileName     string
	Replaces         map[string]string
}


type LeetCodeProblemDetail struct{
	ID  string `json:"questionId"`
	Title string `json:"title"`
	TitleSlug string`json:"titleSlug"`
	Content string`json:"content"`
	Difficulty string`json:"difficulty"`
	CodeSnippets []LeetCodeCodeSnippet`json:"codeSnippets"`
}

type LeetCodeCodeSnippet struct{
	Language string`json:"lang"`
	LanguageSlug string`json:"langSlug"`
	Code string`json:"code"`
}