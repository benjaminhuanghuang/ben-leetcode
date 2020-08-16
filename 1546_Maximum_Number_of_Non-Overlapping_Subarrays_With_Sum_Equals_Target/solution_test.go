/*
1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target

Level: Medium

https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target
*/
package leetcode1546

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
