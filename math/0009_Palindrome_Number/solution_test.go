// https://leetcode.com/problems/palindrome-number
package leetcode0009

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input int
		ans   bool
	}{
		{
			121,
			true,
		},
		{
			-121,
			false,
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, isPalindrome(tc.input), tc.ans)
	}
}
