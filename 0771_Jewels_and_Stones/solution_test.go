// https://leetcode.com/problems/jewels-and-stones
package leetcode0771

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input_J string
		input_S string
		ans     int
	}{
		{
			"aA",
			"aAAbbbb",
			3,
		},
		{
			"z",
			"ZZ",
			0,
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, tc.ans)
	}
}
