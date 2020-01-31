/*
242. Valid Anagram

Level: Easy

https://leetcode.com/problems/valid-anagram
*/
package leetcode0242

/*

 */

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	array := make([]int, 26)

	for i := 0; i < len(s); i++ {
		array[int(s[i])-int('a')]++
		array[int(s[i])-int('a')]--
	}
	for _, i := range array {
		if i != 0 {
			return false
		}
	}
	return true
}

func isAnagramUnicode(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	dict := make(map[rune]int)

	for _, c := range s {
		dict[c]++
	}

	for _, c := range t {
		dict[c]--
		if dict[c] < 0 {
			return false
		}
	}
	return true
}
