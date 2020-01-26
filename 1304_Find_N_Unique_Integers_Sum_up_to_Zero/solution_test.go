// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero
package leetcode1304
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
			3,
			[]int{-1,0,1},
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, sumZero(tc.input), tc.ans)
	}
}
