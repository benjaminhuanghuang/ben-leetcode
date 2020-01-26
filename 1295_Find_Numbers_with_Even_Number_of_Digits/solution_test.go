// https://leetcode.com/problems/find-numbers-with-even-number-of-digits
package leetcode1295
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
			[]int{12,345,2,6,7896},
			2,
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, findNumbers(tc.input))
	}
}

func Test_getDigits(t *testing.T) {
	testCases := []struct {
		input int
		ans   int
	}{
		{
			7896,
			4,
		},
		{
			1,
			1,
		},
		{
			12,
			2,
		},
		{
			345,
			3,
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, getDigits(tc.input))
	}
}
