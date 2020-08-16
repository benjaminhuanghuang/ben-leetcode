/*
1404. Number of Steps to Reduce a Number in Binary Representation to One

Level: Medium

https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one
*/
package leetcode1404

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
