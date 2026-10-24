/*
739. Daily Temperatures

https://leetcode.com/problems/daily-temperatures/
*/

/*
  Solution: 
  https://zxi.mytechroad.com/blog/algorithms/array/leetcode-739-daily-temperatures/

  Stack

    Use a stack to track indices of future warmer days. From top to bottom: recent to far away.

    Time complexity: O(n)
    Space complexity: O(n)

*/
function dailyTemperatures(temperatures: number[]): number[] {
  const n: number = temperatures.length;
  // store indices of days, from top to bottom, the temperatures are in ascending order
  const stack: number[] = [];
  const ans: number[] = Array(n).fill(0);

  for (let i = n - 1; i >= 0; --i) {
    // pop the item that is lower than the current temp
    // from top to bottom, the temperatures are in ascending order
    while (
      stack.length > 0 &&
      temperatures[stack[stack.length - 1]] <= temperatures[i]
    ) {
      stack.pop();
    }
    // answer[i] is the number of days you have to wait after the ith day
    ans[i] = stack.length === 0 ? 0 : stack[stack.length - 1] - i;
    stack.push(i);
  }

  return ans;
}

function dailyTemperatures_2(temperatures: number[]): number[] {
  const len = temperatures.length;
  const ans = Array(len).fill(0);
  const stack: [number, number][] = []; // [temperature, index]

  for (let i = 0; i < len; i++) {
    // pop until the current temperature is lower than the top of the stack
    while (stack.length > 0 && temperatures[i] > stack[stack.length - 1][0]) {
      const top = stack.pop()!;
      ans[top[1]] = i - top[1];
    }
    // push the lower temperature with its index
    stack.push([temperatures[i], i]);
  }
  return ans;
}
