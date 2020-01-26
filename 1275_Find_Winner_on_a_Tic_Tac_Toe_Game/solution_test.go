// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game
package leetcode1275
import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input [][]int
		ans   string
	}{
		{
			[][]int{[]int{0,0},[]int{2,0},[]int{1,1},[]int{2,1},[]int{2,2},},
			"A",
		},
		{
			[][]int{[]int{0,0},[]int{1,1},[]int{0,1},[]int{0,2},[]int{1,0},[]int{2,0},},
			"B",
		},
		{
			[][]int{[]int{0,0},[]int{1,1},[]int{2,0},[]int{1,0},[]int{1,2},[]int{2,1},[]int{0,1},[]int{0,2}, []int{2,2},},
			"Draw",
		},
		{
			[][]int{[]int{0,0},[]int{1,1},},
			"Pending",
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, tictactoe(tc.input))
	}
}
