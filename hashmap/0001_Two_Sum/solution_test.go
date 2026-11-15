package leetcode0001

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		values []int
		target int
		ans    []int
	}{
		// Normal
		{
			[]int{2, 7, 11, 15},
			9,
			[]int{0, 1},
		},
		// Edge
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, twoSum(tc.values, tc.target))
	}
}
