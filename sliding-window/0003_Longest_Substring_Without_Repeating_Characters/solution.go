// https://leetcode.com/problems/longest-substring-without-repeating-characters/
package leetcode0003

/*
https://www.bilibili.com/video/av62451040?p=14
lastOccurrd[ch] 记录ch最后出现的位置
lastOccurrd[ch] 不存在, or < start -> 无需操作
lastOccurrd[ch] >= start -> Update start

update lastOccurrd[ch] and maxLength
*/

func lengthOfLongestSubstring(s string) int {
	lastOccurred := make(map[byte]int)
	start := 0
	maxLength := 0

	for i, ch := range []byte(s) {
		if lastPos, ok := lastOccurred[ch]; ok && lastPos >= start {
			start = lastPos + 1
		}
		if i-start+1 > maxLength {
			maxLength = i - start + 1
		}
		lastOccurred[ch] = i
	}
	return maxLength
}

func lengthOfLongestSubstringUnicode(s string) int {
	lastOccurred := make(map[rune]int)
	start := 0
	maxLength := 0

	for i, ch := range []rune(s) {

		if lastI, ok := lastOccurred[ch]; ok && lastI >= start {
			start = lastI + 1
		}
		if i-start+1 > maxLength {
			maxLength = i - start + 1
		}
		lastOccurred[ch] = i
	}
	return maxLength
}
