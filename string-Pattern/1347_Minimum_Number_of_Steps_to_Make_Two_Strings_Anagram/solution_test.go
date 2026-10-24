/*
1347. Minimum Number of Steps to Make Two Strings Anagram

Level: Medium

https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram
*/
package leetcode1347

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input []int
		ans   []int
	}{
		{
			[]int{2, 7, 11, 15},
			[]int{2, 7, 11, 15},
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, tc.ans)
	}
}
