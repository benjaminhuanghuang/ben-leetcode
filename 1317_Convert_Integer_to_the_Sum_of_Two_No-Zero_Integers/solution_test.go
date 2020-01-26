// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
package leetcode1317
import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input int
		ans   []int
	}{
		{
			2,
			[]int{1,1},
		},
		{
			1010,
			[]int{11,999},
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, tc.ans)
	}
}
