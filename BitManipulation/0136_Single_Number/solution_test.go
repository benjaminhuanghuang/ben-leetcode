// https://leetcode.com/problems/single-number
package leetcode0136

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input []int
		ans   int
	}{
		{
			[]int{2, 2, 1},
			1,
		},
		{
			[]int{4, 1, 2, 1, 2},
			4,
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, tc.ans)
	}
}
