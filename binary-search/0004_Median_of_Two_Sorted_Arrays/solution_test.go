package leetcode0004

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	ast := assert.New(t)

	testCases := []struct {
		input1 []int
		input2 []int
		ans    float64
	}{
		// Normal
		{
			[]int{1,3},
			[]int{2},
			2.0,
		},
		{
			[]int{1,2},
			[]int{3,4},
			2.5,
		},
		// Edge
	}


	for _, tc := range testCases {
		ast.Equal(tc.ans, findMedianSortedArrays(tc.input1, tc.input2))
	}
}