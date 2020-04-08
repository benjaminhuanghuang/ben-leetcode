// https://leetcode.com/problems/merge-intervals
package leetcode0056

import "sort"

/*

 */

// Interval Definition for an interval.
type Interval struct {
	Start int
	End   int
}

func merge(intervals [][]int) [][]int {
	if len(intervals) <= 1 {
		return intervals
	}

	sort.Slice(intervals, func(i int, j int) bool {
		return intervals[i].Start < intervals[j].Start
	})

	res := make([]Interval, 0, len(intervals))

	temp := intervals[0]
	for i := 1; i < len(its); i++ {
		if intervals[i].Start <= temp.End {
			temp.End = max(temp.End, intervals[i].End)
		} else {
			res = append(res, temp)
			temp = intervals[i]
		}
	}
	res = append(res, temp)

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
