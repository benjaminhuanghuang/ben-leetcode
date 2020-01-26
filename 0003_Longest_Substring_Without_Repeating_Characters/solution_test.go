package leetcode0003

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input string
		ans   int
	}{
		// Normal
		{
			"abcabcbb",
			3,
		},
		{
			"bbbbb",
			1,
		},
		{
			"pwwkew",
			3,
		},
		// Edge
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, lengthOfLongestSubstring(tc.input))
	}
}