// https://leetcode.com/problems/next-permutation
package leetcode0031
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
			[]int{1, 2, 3},
			[]int{1, 3, 2},
		},
		{
			[]int{3, 2, 1},
			[]int{1, 2, 3},
		},
		{
			[]int{1, 1, 5},
			[]int{1, 5, 1},
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.input, tc.ans)
	}
}
