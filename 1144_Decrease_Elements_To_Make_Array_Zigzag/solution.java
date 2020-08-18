/*
1144. Decrease Elements To Make Array Zigzag

Level: Medium

https://leetcode.com/problems/decrease-elements-to-make-array-zigzag
*/
package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
  Solution: 
  https://www.youtube.com/watch?v=SD99cAHkRow
*/
class Solution {
  public int movesToMakeZigzag(int[] nums) {
    int oddans = 0;
    int evenans = 0;
    int max = 0;
    int len = nums.length;
    if (len < 3)
      return 0;

    // (big small big small)
    for (int i = 1; i < nums.length; i += 2) { // track small
      if (i == nums.length - 1)
        max = nums[i - 1];
      else
        max = Math.min(nums[i - 1], nums[i + 1]);
      // check if it is (big small big small)
      if (nums[i] >= max)
        oddans += 1 + nums[i] - max;
    }

    // (small big small big)
    for (int i = 0; i < nums.length; i += 2) { // track small
      if (i == 0)
        max = nums[i + 1];
      else if (i == nums.length - 1)
        max = nums[i - 1];
      else
        max = Math.min(nums[i - 1], nums[i + 1]);
      // check if it is (big small big small)
      if (nums[i] >= max)
        evenans += 1 + nums[i] - max;
    }
    return Math.min(evenans, oddans);
  }
}