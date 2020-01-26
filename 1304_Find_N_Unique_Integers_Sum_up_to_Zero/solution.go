// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero
package leetcode1304

/*
Time complexity: O(n)
Space complexity: O(1)
*/
func sumZero(n int) []int {
	ans := make([]int, 0, n) // mach faster by using capacity
	for i := 1; i <= n/2; i++ {
		ans = append(ans, i)
		ans = append(ans, -i)
	}
	if len(ans) != n {
		ans = append(ans, 0)
	}
	return ans
}
