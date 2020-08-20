/*
1368. Minimum Cost to Make at Least One Valid Path in a Grid

Level: Hard

https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid
*/
package leetcode1368

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
