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
	FileExtension    string
	SolutionFileName string
	TestFileName     string
	Replaces         map[string]string
}

