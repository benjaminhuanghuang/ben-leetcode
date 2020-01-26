// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer
package leetcode1281
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
			234,
			15,
		},
		{
			4421,
			21,
		},
		{
			114,
			-2,
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, subtractProductAndSum(tc.input))
	}
}
