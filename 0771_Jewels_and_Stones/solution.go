// https://leetcode.com/problems/jewels-and-stones
package leetcode0771

import (
	"strings"
)

func numJewelsInStones(J string, S string) int {
	set := make(map[byte]bool)

	for i := 0; i < len(J); i++ {
		set[J[i]] = true
	}
	c := 0
	for i := 0; i < len(S); i++ {
		if _, ok := set[S[i]]; ok {
			c++
		}
	}
	return c
}

func numJewelsInStones_more_space(J string, S string) int {
	set := make(map[rune]struct{})

	for _, letter := range J {
		set[letter] = struct{}{}
	}
	c := 0
	for _, letter := range S {
		if _, ok := set[letter]; ok {
			c++
		}
	}
	return c
}

/*
	O(n* m)
*/
func numJewelsInStones_1(J string, S string) int {
	c := 0
	for _, letter := range S {
		// strings.Contains go through J
		if strings.Contains(J, string(letter)) {
			c++
		}
	}
	return c
}
