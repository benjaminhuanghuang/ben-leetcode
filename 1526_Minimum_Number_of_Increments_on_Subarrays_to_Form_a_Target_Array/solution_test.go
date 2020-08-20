/*
1526. Minimum Number of Increments on Subarrays to Form a Target Array

Level: Hard

https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array
*/
package leetcode1526

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
