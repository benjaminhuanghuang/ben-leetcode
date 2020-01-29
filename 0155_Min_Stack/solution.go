/*
155. Min Stack

Level: Easy

https://leetcode.com/problems/min-stack
*/
package leetcode0155

/*

 */

type MinStack struct {
	data     []int
	minValue []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{
		data:     make([]int, 0),
		minValue: make([]int, 0),
	}
}

func (this *MinStack) Push(x int) {
	if len(this.data) == 0 {
		this.data = append(this.data, x)
		this.minValue = append(this.minValue, x)
		return
	}

	min := this.GetMin()
	this.data = append(this.data, x)
	if min > x {
		this.minValue = append(this.minValue, x)
	} else {
		this.minValue = append(this.minValue, min)
	}
}

func (this *MinStack) Pop() {
	if len(this.data) == 0 || len(this.minValue) == 0 {
		panic("No data in statck")
	}
	this.data = this.data[:len(this.data)-1]
	this.minValue = this.minValue[:len(this.minValue)-1]
}

func (this *MinStack) Top() int {
	if len(this.data) == 0 {
		panic("No data in statck")
	}
	return this.data[len(this.data)-1]
}

func (this *MinStack) GetMin() int {
	if len(this.minValue) == 0 {
		panic("No data in statck")
	}
	return this.minValue[len(this.minValue)-1]
}
