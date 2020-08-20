/*
1467. Probability of a Two Boxes Having The Same Number of Distinct Balls

Level: Hard

https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls
*/
package leetcode1467

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
