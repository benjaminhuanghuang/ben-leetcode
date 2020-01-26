// https://leetcode.com/problems/minimum-time-visiting-all-points
package leetcode1266
import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input [][]int
		ans   int
	}{
		{
			[][]int{[]int{3,2},[]int{-2,2}},
			5,
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, minTimeToVisitAllPoints(tc.input))
	}
}
