/*
1508. Range Sum of Sorted Subarray Sums

Level: Medium

https://leetcode.com/problems/range-sum-of-sorted-subarray-sums
*/
package leetcode1508

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
