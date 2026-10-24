/*
1475. Final Prices With a Special Discount in a Shop

https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
*/

/*
Approach: Monotonic Stack

https://youtu.be/X98Yc4YtgyA (HuaHua)
https://zxi.mytechroad.com/blog/stack/leetcode-1475-final-prices-with-a-special-discount-in-a-shop/

Store the first smaller element in the stack.

Use a monotonic stack to store the item in increasing order. Whenever encounter a cheaper item than the top, pop the
stack.

Use a stack to store monotonically increasing items, when the current item is cheaper than the top 
of the stack, we get the discount and pop that item. Repeat until the current item is no longer 
cheaper or the stack becomes empty.

用一个栈存“还没找到折扣”的下标

Time complexity: O(n)
Space complexity: O(n)

*/
function finalPrices(prices: number[]): number[] {
  // Stack to store indices of monotonically increasing elements
  const s: number[] = [];

  for (let i = 0; i < prices.length; i++) {
    // pop all elements that are greater than or equal to the current element
    // and update the discount
    while (s.length > 0 && prices[s[s.length - 1]] >= prices[i]) {
      prices[s.pop() as number] -= prices[i];
    }
    s.push(i);
  }

  return prices;
}

/*
    Approach: Brute Force
    Time complexity: O(n^2)
    Space complexity: O(1)
*/

function finalPrices_BF(prices: number[]): number[] {
  const n = prices.length;
  for (let i = 0; i < n; ++i) {
    for (let j = i + 1; j < n; ++j) {
      if (prices[j] <= prices[i]) {
        prices[i] -= prices[j];
        break;
      }
    }
  }
  return prices;
}
