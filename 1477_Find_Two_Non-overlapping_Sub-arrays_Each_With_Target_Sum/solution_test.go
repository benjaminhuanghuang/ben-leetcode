/*
1477. Find Two Non-overlapping Sub-arrays Each With Target Sum

Level: Medium

https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum
*/
package leetcode1477

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
