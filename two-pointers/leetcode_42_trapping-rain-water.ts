/*
42. Trapping Rain Water

https://leetcode.com/problems/trapping-rain-water/
*/

/*
Huahua
https://www.youtube.com/watch?v=StH5vntauyQ

Approach 3: Two Pointers
Use two v ariables to store the max height from left and right

Use l, r to track tow sides. Move l, r based on whether max_l < max_r or max_l >= max_r
if max_l < max_r, move l to the right, answer depends on max_l, so we move l

Time complexity: O(N)
Space complexity: O(1)
*/
function trap_2Pointers(height: number[]): number {
  const n = height.length;
  if (n === 0) return 0;

  let l = 0;
  let r = n - 1;
  let max_l = height[l];
  let max_r = height[r];
  let ans = 0;

  while (l < r) {
    if (max_l < max_r) {
      // when max_l < max_r, the answer depends on max_l, so we move l
      ans += max_l - height[l];
      max_l = Math.max(max_l, height[++l]);
    } else {
      ans += max_r - height[r];
      max_r = Math.max(max_r, height[--r]);
    }
  }

  return ans;
}

function trap(height: number[]): number {
  const n = height.length;
  const leftMax = new Array(n);
  const rightMax = new Array(n);

  //下标 0 到 i 之间最高的柱子（包括 i 自己）
  leftMax[0] = height[0];
  for (let i = 1; i < n; i++) {
    //前面的最高已经算好存在 leftMax[i-1] 里,只要跟当前这一根比一下，大的那个就是 0..i 的最高
    leftMax[i] = Math.max(leftMax[i - 1], height[i]);
  }

  // 下标 i 到最后之间最高的柱子（包括 i 自己）
  rightMax[n - 1] = height[n - 1];
  for (let i = n - 2; i >= 0; i--) {
    rightMax[i] = Math.max(rightMax[i + 1], height[i]);
  }

  let water = 0;
  for (let i = 0; i < n; i++) {
    water += Math.min(leftMax[i], rightMax[i]) - height[i];
  }
  return water;
}
