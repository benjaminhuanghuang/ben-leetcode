// https://leetcode.com/problems/decompress-run-length-encoded-list
package leetcode1313
import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input []int
		ans   []int
	}{
		{
			[]int{1, 2, 3, 4},
			[]int{2, 4, 4, 4},
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, tc.ans)
	}
}
