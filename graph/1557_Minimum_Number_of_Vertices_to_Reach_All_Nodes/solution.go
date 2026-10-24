/*
1557. Minimum Number of Vertices to Reach All Nodes

Level: Medium

https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes
*/
package leetcode1557

/*
  Solution:
  https://www.acwing.com/file_system/file/content/whole/index/content/1188798/

  有入度的点一定能从某个起点开始的路径覆盖到，所以这道题的答案就是所有入度为 0 的点。

*/
func findSmallestSetOfVertices(n int, edges [][]int) []int {
	hasPredecessor := make([]bool, n)
	for _, e := range edges {
		hasPredecessor[e[1]] = true
	}

	ans := make([]int, 0)
	for i := 0; i < n; i++ {
		if !hasPredecessor[i] {
			ans = append(ans, i)
		}
	}

	return ans
}
