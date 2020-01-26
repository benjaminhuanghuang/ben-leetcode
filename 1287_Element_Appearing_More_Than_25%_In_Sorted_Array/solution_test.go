// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array
package leetcode1287
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
			[]int{1,2,2,6,6,6,6,7,10},
			6,
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, findSpecialInteger(tc.input))
	}
}
