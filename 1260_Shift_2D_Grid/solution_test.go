// https://leetcode.com/problems/shift-2d-grid
package leetcode1260
import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input [][]int
		k int
		ans   [][]int
	}{
		{
			[][]int{[]int{1,2,3},[]int{4,5,6},[]int{7,8,9}},
			1,
			[][]int{[]int{9,1,2},[]int{3,4,5},[]int{6,7,8}},
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, shiftGrid(tc.input, tc.k))
	}
}
