package leetcode0100

import (
	"testing"

	"github.com/stretchr/testify/assert"

	. "../common"
)

func Test_OK(t *testing.T) {
	ast := assert.New(t)

	t1 := BuildTreeInLevelOrder([]int{1, 2, 3})
	t2 := BuildTreeInLevelOrder([]int{1, 2, 3})
	ast.Equal(true, isSameTree(t1, t2))
}
