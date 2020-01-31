/*
412. Fizz Buzz

Level: Easy

https://leetcode.com/problems/fizz-buzz
*/
package leetcode0412

import (
	"strconv"
)

/*

 */
func fizzBuzz(n int) []string {
	ans := make([]string, n)
	for i := 1; i <= n; i++ {
		if i%15 == 0 {
			ans[i-1] = "FizzBuzz"
		} else if i%3 == 0 {
			ans[i-1] = "Fizz"
		} else if i%5 == 0 {
			ans[i-1] = "Buzz"
		} else {
			ans[i-1] = strconv.Itoa(i)
		}
	}
	return ans
}
