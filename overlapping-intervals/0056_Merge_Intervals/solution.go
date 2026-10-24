// https://leetcode.com/problems/merge-intervals
package leetcode0056

import "sort"

/*
https://leetcode.com/problems/merge-intervals
*/

func merge(intervals [][]int) [][]int {
	if len(intervals) <= 1 {
		return intervals
	}

	sort.Slice(intervals, func(i int, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	res := make([][]int, 0, len(intervals))

	for i := 0; i < len(intervals); i++ {
		newInterval := []int{intervals[i][0], intervals[i][1]}
		for i < len(intervals)-1 && newInterval[1] >= intervals[i+1][0] {
			newInterval[1] = max(intervals[i+1][1], newInterval[1])
			i++
		}
		res = append(res, newInterval)
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
