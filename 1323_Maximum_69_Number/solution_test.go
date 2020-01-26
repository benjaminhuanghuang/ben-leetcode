// https://leetcode.com/problems/maximum-69-number
package leetcode1323

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
			9669,
			9969,
		},
		{
			9996,
			9999,
		},
		{
			9999,
			9999,
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, maximum69Number(tc.input), tc.ans)
	}
}
