/*
1470. Shuffle the Array

Level: Easy

https://leetcode.com/problems/shuffle-the-array
*/
package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
  Solution: 
*/
class Solution {
  public int[] shuffle(int[] nums, int n) {
    int arr[] = new int[2 * n];
    for (int i = 0, j = n, index = 0; i < n; i++, j++, index += 2) {
      arr[index] = nums[i];
      arr[index + 1] = nums[j];

    }
    return arr;
  }

}