// https://leetcode.com/problems/reverse-integer
package leetcode0007
import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input int
		ans   int
	}{
		{
			123,
			321,
		},
		{
			-123,
			-321,
		},
		{
			120,
			21,
		},
		{
			1534236469,
			0,
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, reverse(tc.input), tc.ans)
	}
}
