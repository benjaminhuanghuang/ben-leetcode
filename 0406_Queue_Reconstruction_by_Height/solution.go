/*
406. Queue Reconstruction by Height

Level: Medium

https://leetcode.com/problems/queue-reconstruction-by-height
*/
package leetcode0406

import "sort"

/*

 */
func reconstructQueue(people [][]int) [][]int {
	res := make([][]int, 0, len(people))

	// 按照 Persons 的排序方式，对 people 进行排序
	sort.Sort(Persons(people))

	// 把 person 插入到 res[idx] 上
	insert := func(idx int, person []int) {
		res = append(res, person)
		// 插入到末尾
		if len(res)-1 == idx {
			return
		}
		// 插入到中间位置
		copy(res[idx+1:], res[idx:])
		res[idx] = person
	}

	for _, p := range people {
		insert(p[1], p)
	}

	return res
}

// Persons 实现了 sort.Interface 接口
type Persons [][]int

func (p Persons) Len() int {
	return len(p)
}

// 以 h 的降序为主
// 以 k 的升序为辅
func (p Persons) Less(i, j int) bool {
	if p[i][0] == p[j][0] {
		return p[i][1] < p[j][1]
	}
	return p[i][0] > p[j][0]
}

func (p Persons) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}
