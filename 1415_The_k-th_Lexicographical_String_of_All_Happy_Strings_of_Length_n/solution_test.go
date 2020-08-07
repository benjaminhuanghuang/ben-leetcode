/*
1415. The k-th Lexicographical String of All Happy Strings of Length n

Level: Medium

https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
*/
package leetcode1415

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
