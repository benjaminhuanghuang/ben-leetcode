// https://leetcode.com/problems/sort-array-by-parity
package leetcode0905
import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input []int
		ans   [][]int
	}{
		{
			[]int{3, 1, 2, 4},
			[][]int{[]int{2,4,1,3}, []int{4, 2, 3, 1},[]int{2, 4, 3, 1}, []int{4, 2, 1, 3}},
		},
	}

	for _, tc := range testCases {
		assert.Contains(t, tc.ans, sortArrayByParity(tc.input))
	}
}