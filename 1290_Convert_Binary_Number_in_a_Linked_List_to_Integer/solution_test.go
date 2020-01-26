// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
package leetcode1290

import (
	"testing"

	"github.com/stretchr/testify/assert"

	. "../common"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input *ListNode
		ans   int
	}{
		{
			BuildList(1, 0, 1),
			5,
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, getDecimalValue(tc.input))
	}
}
