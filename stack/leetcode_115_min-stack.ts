/*
155. Min Stack
*/

class MinStack {
  stack: number[];
  minStack: number[];

  constructor() {
    this.stack = [];
    this.minStack = [];
  }

  /**
   * Push element x onto stack.
   * Time Complexity: O(1);
   * Space Complexity: O(n);
   */
  push(x: number): void {
    this.stack.push(x);
    const currMin =
      this.minStack.length == 0
        ? x
        : Math.min(this.minStack[this.minStack.length - 1], x);
    this.minStack.push(currMin);
  }

  /**
   * Removes the element on top of the stack.
   * Time Complexity: O(1);
   * Space Complexity: O(1);
   */
  pop(): void {
    this.stack.pop();
    this.minStack.pop();
  }

  /**
   * Get the top element.
   * Time Complexity: O(1);
   * Space Complexity: O(1);
   */
  top(): number {
    return this.stack[this.stack.length - 1];
  }

  /**
   * Retrieve the minimum element in the stack.
   * Time Complexity: O(1);
   * Space Complexity: O(1);
   */
  getMin(): number {
    return this.minStack[this.minStack.length - 1];
  }
}
