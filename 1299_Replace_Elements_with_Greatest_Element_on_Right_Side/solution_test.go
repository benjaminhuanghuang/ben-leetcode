// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side
package leetcode1299
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
			[]int{17,18,5,4,6,1},
			[]int{18,6,6,6,1,-1},
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, replaceElements(tc.input), tc.ans)
	}
}
