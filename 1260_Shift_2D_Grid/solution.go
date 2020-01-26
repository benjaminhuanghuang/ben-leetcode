// https://leetcode.com/problems/shift-2d-grid
package leetcode1260
/*
	1. Move every column right, except last column
	2. Move last column to first column
	3. Move the bottom-right corner one
 */

 func shiftGrid(grid [][]int, k int) [][]int {
	n, m := len(grid), len(grid[0])
	res := make([][]int, n)
	for i := 0; i < n; i++ {
			res[i] = make([]int, m)
	}
	
	for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
					t := j + k
					res[(i + t / m)%n][t % m] = grid[i][j]
			}
	}
	return res
}
/*
Time complexity: O(k*n*m)
Space complexity: O(1) in-place
*/
func shiftGridSimulation(grid [][]int, k int) [][]int {
	n, m := len(grid), len(grid[0])
	for k > 0{
		last := grid[n - 1][m - 1];
		for i := n-1; i >=0; i-- {
				for j := m-1; j >=0; j-- {
					if i == 0 && j == 0{
						// grid[m - 1][n - 1] moves to grid[0][0]
						grid[i][j] = last;
					} else if j == 0 {
						grid[i][j] = grid[i - 1][m - 1];
					} else {
						grid[i][j] = grid[i][j - 1];
					}
				}
		}
		k-- 
	}
	return grid
}