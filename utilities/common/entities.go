package common

type ProblemItem struct {
	Number int
	Title  string
	Level  string
	Url    string
	Tag    string
}
type LanguageSetting struct {
	FileExtension    string
	SolutionFileName string
	TestFileName     string
	Replaces         map[string]string
}
