package leetcode0101

import (
	"testing"

	"github.com/stretchr/testify/assert"

	. "../common"
)

func Test_OK(t *testing.T) {
	ast := assert.New(t)

	tree := BuildTreeInLevelOrder([]int{1, 2, 2, 3, 4, 4, 3})
	ast.Equal(true, isSymmetric(tree))
}

func Test_OK2(t *testing.T) {
	ast := assert.New(t)

	tree := BuildTreeInLevelOrder([]int{1, 2, 2, NIL_NODE, 3, NIL_NODE, 3})
	ast.Equal(false, isSymmetric(tree))
}
