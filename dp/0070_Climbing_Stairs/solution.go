// https://leetcode.com/problems/climbing-stairs
package leetcode0070
/*
	
 */

func climbStairs(n int) int {
    if n == 1 {
			return 1
		}
		prevPrev = 1
		prev = 1
		for i := 2; i <= n; i++ {
			current = s2 + s1
			prevPrev = prev
			prev = current
		}
		return prev
}

func climbStairs(n int) int {
	if n < 2 {
		return 1
	}

	rec := make([]int, n+1)
	rec[0], rec[1] = 1, 1

	for i := 2; i <= n; i++ {
		rec[i] = rec[i-1] + rec[i-2]
	}

	return rec[n]
}