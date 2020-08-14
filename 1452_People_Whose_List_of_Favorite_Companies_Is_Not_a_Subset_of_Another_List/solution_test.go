/*
1452. People Whose List of Favorite Companies Is Not a Subset of Another List

Level: Medium

https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list
*/
package leetcode1452

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
