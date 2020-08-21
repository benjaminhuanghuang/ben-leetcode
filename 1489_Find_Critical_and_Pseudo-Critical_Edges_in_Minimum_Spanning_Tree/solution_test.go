/*
1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

Level: Hard

https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree
*/
package leetcode1489

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
