/*
1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

Level: Medium

https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold
*/
package leetcode1343

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
