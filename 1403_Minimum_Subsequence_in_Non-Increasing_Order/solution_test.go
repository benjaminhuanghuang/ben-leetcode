/*
1403. Minimum Subsequence in Non-Increasing Order

Level: Easy

https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order
*/
package leetcode1403

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
