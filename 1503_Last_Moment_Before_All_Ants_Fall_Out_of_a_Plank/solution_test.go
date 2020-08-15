/*
1503. Last Moment Before All Ants Fall Out of a Plank

Level: Medium

https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank
*/
package leetcode1503

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
			[]int{2, 7, 11, 15},
			[]int{2, 7, 11, 15},
		},
	}

	for _, tc := range testCases {
		assert.Equal(t, tc.ans, tc.ans)
	}
}
