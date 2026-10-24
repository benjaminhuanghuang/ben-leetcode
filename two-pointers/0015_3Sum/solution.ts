/*
15. 3Sum

https://leetcode.com/problems/3sum/
*/

/*
Time complexity: O(n^2)
*/
function threeSum(nums: number[]): number[][] {
  const res: number[][] = [];
  nums.sort((a, b) => a - b);

  for (let i = 0; i < nums.length; i++) {
    if (i !== 0 && nums[i - 1] === nums[i]) {
      // skip the numbers that are the same as the previous one
      continue;
    }
    let start = i + 1;
    let end = nums.length - 1;

    while (start < end) {
      if (start !== i + 1 && nums[start] === nums[start - 1]) {
        // skip the numbers that are the same as the previous one
        start++;
        continue;
      }

      const sum = nums[i] + nums[start] + nums[end];
      if (sum === 0) {
        res.push([nums[i], nums[start], nums[end]]);
        start++;
      } else if (sum < 0) {
        start++;
      } else {
        end--;
      }
    }
  }

  return res;
}
