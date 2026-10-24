/*
136. Single Number

Level: Easy

https://leetcode.com/problems/single-number
*/
package leetcode0136
/*
	
 */
func singleNumber(nums []int) int {
	ans:=0	
	for _, n:=range nums {
			ans = ans ^n
		}
	return ans
}