/*
48. Rotate Image

Level: Medium

https://leetcode.com/problems/rotate-image
*/
package leetcode0048

/*
	一圈(layer)一圈的移动, layerNum := n / 2
*/
func rotate(matrix [][]int) {
	n := len(matrix)
	layerNum := n / 2
	for layer := 0; layer < layerNum; layer++ {
		start := layer
		end := n - 1 - layer

		for i := start; i < end; i++ {
			offset := i - start
			temp := matrix[start][i] // backup the up layer
			// left to up
			matrix[start][i] = matrix[end-offset][start]
			// bottom to left
			matrix[end-offset][start] = matrix[end][end-offset]
			// right to bottom
			matrix[end][end-offset] = matrix[i][end]
			// up to right
			matrix[i][end] = temp
		}
	}
}
