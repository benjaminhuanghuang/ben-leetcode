// https://leetcode.com/problems/add-two-numbers
package leetcode0002

import (
	. "../common"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Simle(t *testing.T) {
	list1 := BuildList(2, 4, 3)
	list2 := BuildList(5, 6, 4)

	result := addTwoNumbers(list1, list2)
	PrintList("result is:",result)
	expected := BuildList(7, 0, 8)
	assert.Equal(t, true, IsSameList(result, expected))
}

func Test_Differnt_Length(t *testing.T) {
	list1 := BuildList(1, 8)
	list2 := BuildList(0)

	result := addTwoNumbers(list1, list2)
	PrintList("result is:",result)
	expected := BuildList(1, 8)
	assert.Equal(t, true, IsSameList(result, expected))
}

