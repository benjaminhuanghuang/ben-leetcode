// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side
package leetcode1299

/*
	Time complexity: O(n)
	Space complexity: O(1)
*/

func replaceElements(arr []int) []int {
	greatest := -1
	for i := len(arr) - 1; i >= 0; i-- {
		origin := arr[i]
		arr[i] = greatest
		if origin > greatest {
			greatest = origin
		}
	}

	return arr
}
