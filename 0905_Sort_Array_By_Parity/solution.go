// https://leetcode.com/problems/sort-array-by-parity
package leetcode0905

/*

 */

 func sortArrayByParity(A []int) []int {
	for i, j := 0, len(A) - 1; i < j; {
			if A[i] %2 == 0 {
					i++
			} else if A[j] %2 != 0 {
					j--
			} else {
					A[i], A[j] = A[j], A[i]
			}
	}
	
	return A
}

func sortArrayByParity_1(A []int) []int {
	ans := make([]int, len(A))

	i := 0          // even
	j := len(A) - 1 // odd
	for _, n := range A {
		if n%2 == 0 {
			ans[i] = n
			i++
		} else {
			ans[j] = n
			j--
		}
	}
	return ans
}
