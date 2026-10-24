/*
1239. Maximum Length of a Concatenated String with Unique Characters

Level: Medium

https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters
*/
package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;
/*
  Solution: 
*/
class Solution {
  int res = 0;
  public int maxLength(List<String> arr) {
      backtracking(arr, new HashSet<>(), 0);
      return res;
  }
  
  private void backtracking(List<String> arr, Set<Character> set, int start) {
      if (start >= arr.size()) return;
      for (int i = start; i < arr.size(); i++) {
          String cur = arr.get(i);
          int j = 0;
          Set<Character> curSet = new HashSet<>();
          for (; j < cur.length(); j++) {
              if (!curSet.add(arr.get(i).charAt(j))) break;
              if (set.contains(arr.get(i).charAt(j)))
                  break;
          }
          if (j == cur.length()) {
              for (char c : cur.toCharArray()) set.add(c);
              res = Math.max(res, set.size());
              backtracking(arr, set, i + 1);
              for (char c : cur.toCharArray()) set.remove(c);
          }
      }
  }
}