/*
1356. Sort Integers by The Number of 1 Bits

Level: Easy

https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits
*/
package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;
/*
  Solution: 
*/
class Solution {
    public int[] sortByBits(int[] arr) {
      Integer[] ar = new Integer[arr.length];
      for(int i = 0; i < arr.length; i++) 
        ar[i] = arr[i];
      
      Arrays.sort(ar, (a, b) -> Integer.bitCount(a) == Integer.bitCount(b) ? a - b : Integer.bitCount(a) - Integer.bitCount(b));
      int[] res = new int[arr.length];
      for(int i = 0; i < arr.length; i++) 
        res[i] = ar[i];
      return res;
    }
}