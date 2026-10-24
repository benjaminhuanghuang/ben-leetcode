// https://leetcode.com/problems/majority-element
package leetcode0169

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
			[]int{3, 2, 3},
			3,
		},
		{
			[]int{2, 2, 1, 1, 1, 2, 2},
			3,
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, tc.ans)
	}
}
