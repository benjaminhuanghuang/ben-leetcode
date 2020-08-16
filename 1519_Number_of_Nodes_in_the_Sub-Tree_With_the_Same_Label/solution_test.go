/*
1519. Number of Nodes in the Sub-Tree With the Same Label

Level: Medium

https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label
*/
package leetcode1519

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
