/*
1443. Minimum Time to Collect All Apples in a Tree

Level: Medium

https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree
*/
package leetcode1443

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
