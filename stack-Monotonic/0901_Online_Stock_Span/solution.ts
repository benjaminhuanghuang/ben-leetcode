/*
901. Online Stock Span

https://leetcode.com/problems/online-stock-span
*/

class StockSpanner {
  // 栈中每个元素是 [price, span]，span 表示这个 price 的"跨度"（包括自己及之前连续 ≤ price 的天数）
  private stack: [number, number][] = [];

  constructor() {}

  next(price: number): number {
    let span = 1;

    // 不断 弹出 栈中所有 “价格 ≤ 当前价格” 的历史记录，同时把它们的 span 累加到当前 span 上。
    // 等于把所有这些连续 “不高于当前价” 的天数合并到当前 span 里。
    while (
      this.stack.length > 0 &&
      this.stack[this.stack.length - 1][0] <= price
    ) {
      const [_oldPrice, oldSpan] = this.stack.pop()!;
      span += oldSpan;
    }

    // 然后把当前 price + 它的 span 推入栈
    this.stack.push([price, span]);

    return span;
  }
}
