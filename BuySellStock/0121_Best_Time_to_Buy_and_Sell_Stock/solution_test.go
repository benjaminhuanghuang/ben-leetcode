// https://leetcode.com/problems/best-time-to-buy-and-sell-stock
package leetcode0121
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
			[]int{7, 1, 5, 3, 6, 4},
			5,
		},
		{
			[]int{7, 6, 4, 3, 1},
			0,
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, maxProfit(tc.input))
	}
}
