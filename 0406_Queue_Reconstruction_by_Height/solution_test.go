/*
406. Queue Reconstruction by Height

Level: Medium

https://leetcode.com/problems/queue-reconstruction-by-height
*/
package leetcode0406

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_OK(t *testing.T) {
	testCases := []struct {
		input [][]int
		ans   [][]int
	}{
		{
			[][]int{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}},
			[][]int{{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}},
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, reconstructQueue(tc.input))
	}
}
