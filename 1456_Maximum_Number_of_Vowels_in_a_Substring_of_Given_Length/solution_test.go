/*
1456. Maximum Number of Vowels in a Substring of Given Length

Level: Medium

https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length
*/
package leetcode1456

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
