/*
1566. Detect Pattern of Length M Repeated K or More Times

Level: Easy

https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times
*/
package leetcode1566

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
