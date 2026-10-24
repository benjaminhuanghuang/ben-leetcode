/*
611. Valid Triangle Number

https://leetcode.com/problems/valid-triangle-number/
*/

/*
    https://zxi.mytechroad.com/blog/math/leetcode-611-valid-triangle-number/
    Sort + Two points
    a + b > c
    a <= b <= c
    Time Complexity:
    O(n^2)
*/

function triangleNumber(nums: number[]): number {
  if (nums.length < 3) return 0;

  // Sort the array in descending order
  nums.sort((a, b) => b - a);

  let n = nums.length;
  let ans = 0;

  // c b........a
  // find a, b, c such that a + b > c
  // c is the largest side, from 0 to n - 2
  // a is the smallest side, from n - 1 to b
  for (let c = 0; c < n - 2; ++c) {
    let b = c + 1;
    let a = n - 1;
    while (b < a) {
      if (nums[a] + nums[b] > nums[c]) {
        ans += a - b;
        ++b;
      } else {
        --a;
      }
    }
  }

  return ans;
}
