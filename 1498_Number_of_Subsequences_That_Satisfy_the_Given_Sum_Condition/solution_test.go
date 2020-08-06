/*
1498. Number of Subsequences That Satisfy the Given Sum Condition

Level: Medium

https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition
*/
package leetcode1498

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
