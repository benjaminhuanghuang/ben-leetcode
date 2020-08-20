/*
1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

Level: Hard

https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons
*/
package leetcode1420

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
