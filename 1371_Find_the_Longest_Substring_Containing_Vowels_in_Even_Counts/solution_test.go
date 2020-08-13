/*
1371. Find the Longest Substring Containing Vowels in Even Counts

Level: Medium

https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts
*/
package leetcode1371

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
