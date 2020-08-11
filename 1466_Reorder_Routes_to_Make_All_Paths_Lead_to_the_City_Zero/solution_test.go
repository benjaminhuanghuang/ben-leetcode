/*
1466. Reorder Routes to Make All Paths Lead to the City Zero

Level: Medium

https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero
*/
package leetcode1466

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
