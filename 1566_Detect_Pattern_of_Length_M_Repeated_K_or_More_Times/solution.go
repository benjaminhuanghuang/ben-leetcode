/*
1566. Detect Pattern of Length M Repeated K or More Times

Level: Easy

https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times
*/
package leetcode1566

/*
  Solution:
*/
func containsPattern(arr []int, m int, k int) bool {
	n := len(arr)
	counter := 0

	for i := 0; i+m < n; i++ {
		if arr[i] == arr[i+m] {
			counter++
		} else {
			counter = 0
		}
		if counter == m*(k-1) {
			return true
		}
	}

	return false
}
