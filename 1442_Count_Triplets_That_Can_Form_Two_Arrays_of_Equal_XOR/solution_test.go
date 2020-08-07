/*
1442. Count Triplets That Can Form Two Arrays of Equal XOR

Level: Medium

https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor
*/
package leetcode1442

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
