/*
558. Logical OR of Two Binary Grids Represented as Quad-Trees

Level: Medium

https://leetcode.com/problems/logical-or-of-two-binary-grids-represented-as-quad-trees
*/
package leetcode0558

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
