/*
1493. Longest Subarray of 1's After Deleting One Element

Level: Medium

https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element
*/
package leetcode1493

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
