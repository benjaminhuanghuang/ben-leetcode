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