/*
1470. Shuffle the Array

Level: Easy

https://leetcode.com/problems/shuffle-the-array
*/
package leetcode1470
/*
  Solution: 
*/
func shuffle(nums []int, n int) []int {
  arr := make([]int, n*2)
  for i,j,index:=0,n,0; i<n ;i,j,index = i+1,j+1,index+2 {
  arr[index] = nums[i]
  arr[index+1] = nums[j]
  }
  return arr
}
