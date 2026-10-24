/*
283. Move Zeroes

Level: Easy

https://leetcode.com/problems/move-zeroes
*/

package leetcode0283

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
			[]int{0, 1, 0, 3, 12},
			[]int{1, 3, 12, 0, 0},
		},
	}

	for _, tc := range testCases {
		moveZeroes(tc.input)
		assert.Equal(t, tc.ans, tc.input)
	}
}
