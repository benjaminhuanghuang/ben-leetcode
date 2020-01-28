/*
1332. Remove Palindromic Subsequences

Level: Easy

https://leetcode.com/problems/remove-palindromic-subsequences
*/
package leetcode1332
/*
  Solution: 
  if s is empty => 0 step
  if s is a palindrome => 1 step
  Otherwise, 2 steps…
  1. delete all the as
  2. delete all the bs

  Time complexity: O(n)
  Space complexity: O(n) / O(1)
*/
func removePalindromeSub(s string) int {
    if len(s) == 0{
      return 0
    }
    reversed := reverseString(s)
    runes := []rune(s)
    if(s == reversed){
      return 1
    }
    return 2
}
func reverseString(s string) string {
  runes := []rune(s)
  for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
    runes[i], runes[j] = runes[j], runes[i]
  }
  return string(runes)
}