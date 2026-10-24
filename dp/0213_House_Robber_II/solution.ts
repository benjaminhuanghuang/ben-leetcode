/*
198. House Robber

https://leetcode.com/problems/house-robber-ii/
*/

/*
因为是环形，不能同时取第一个和最后一个房子。于是把问题 转化成两个「线性」的问题：

不偷第一个房子 → 那么可以考虑偷房子 1 到 n-1（下标从 1 到最后）那一段。

不偷最后一个房子 → 那么考虑偷房子 0 到 n-2（下标从 0 到倒数第二）那一段。

分别对这两个区间使用线性版本 House Robber 的算法，取两者的最大值就是答案
*/
function rob(nums: number[]): number {
  const n = nums.length;
  if (n === 0) return 0;
  if (n === 1) return nums[0];

  // helper: 线性 House Robber
  function robLinear(houses: number[]): number {
    // 这是 DP 的经典写法，使用 两个滚动变量：
    let prevMax = 0; // 到前一个房子之前的最大金额（对应 DP[i-1] 的“前一层”）
    let currMax = 0; // 到当前房子为止的最大金额（对应 DP[i]）
    for (const money of houses) {
      // currMax : 不偷第 i 个房子
      // prevMax + money : 偷第 i 个房子
      const newCurr = Math.max(currMax, prevMax + money);
      prevMax = currMax;
      currMax = newCurr;
    }
    return currMax;
  }

  // 情况 1: 不抢最后一个 → 偷 houses[0 .. n-2]
  const case1 = robLinear(nums.slice(0, n - 1));
  // 情况 2: 不抢第一个 → 偷 houses[1 .. n-1]
  const case2 = robLinear(nums.slice(1));

  return Math.max(case1, case2);
}

export {};
