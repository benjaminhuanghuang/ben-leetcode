// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array
package leetcode1287
/*
	
 */

 func findSpecialInteger(arr []int) int {
	s := len(arr) / 4
	for i := 0; i + s < len(arr); i++{
		if arr[i] == arr[i + s] {
			return arr[i]
		}
	}
	return -1
}