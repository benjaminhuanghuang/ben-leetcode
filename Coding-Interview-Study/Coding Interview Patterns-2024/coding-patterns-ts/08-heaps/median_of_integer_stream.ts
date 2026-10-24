import { Heap } from "./Heap";

/*

leftHalf: Max Heap — keeps the smaller half of numbers
→ Top (peek()) = largest number in the smaller half

rightHalf: Min Heap — keeps the larger half of numbers
→ Top (peek()) = smallest number in the larger half
*/

class median_of_integer_stream {
  private leftHalf: Heap<number>; // Max heap
  private rightHalf: Heap<number>; // Min heap

  constructor() {
    // Max-heap: larger numbers bubble DOWN
    this.leftHalf = new Heap<number>((a, b) => a > b);
    // Min-heap: smaller numbers bubble UP
    this.rightHalf = new Heap<number>((a, b) => a < b);
  }

  add(num: number): void {
    // Decide where to add the new number
    if (!this.leftHalf.peek() || num <= this.leftHalf.peek()!) {
      this.leftHalf.push(num);
    } else {
      this.rightHalf.push(num);
    }

    // Balance heaps so that leftHalf can only be 1 larger
    if (this.leftHalf.size() > this.rightHalf.size() + 1) {
      this.rightHalf.push(this.leftHalf.pop()!);
    } else if (this.leftHalf.size() < this.rightHalf.size()) {
      this.leftHalf.push(this.rightHalf.pop()!);
    }
  }

  getMedian(): number {
    if (this.leftHalf.size() === this.rightHalf.size()) {
      return (this.leftHalf.peek()! + this.rightHalf.peek()!) / 2;
    } else {
      return this.leftHalf.peek()!;
    }
  }
}

/*
Time complexity:
• The time complexity of add is O(log(n)), where n denotes the number of values added to
the data structure. This is because we first push a number to one of the heaps, which takes
O(log(n)) time. Then, if rebalancing is required, we also pop from one heap and push to the
other, where both operations also take O(Iog(n)) time.
• The time complexity of get_media n is 0(1) because accessing the top element of a heap takes
0(1) time.

Space complexity: The space complexity is O(n) because the two heaps together store n elements,
*/
