/*
1111. Maximum Nesting Depth of Two Valid Parentheses Strings

Level: Medium

https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings
*/
package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
  Solution: 
*/
class Solution {
  public int[] maxDepthAfterSplit(String seq) {
    int max = 0;
    int count = 0;
    for (int i = 0; i < seq.length(); ++i) {
      if (seq.charAt(i) == '(') {
        count++;
        max = Math.max(max, count);
      } else {
        count--;
      }
    }

    int depth = max / 2 + max % 2;
    int[] ret = new int[seq.length()];
    count = 0;
    int acount = 0;
    boolean valid = true;
    for (int i = 0; i < seq.length(); ++i) {
      if (seq.charAt(i) == '(') {
        count++;
        if (count <= depth) {
          acount++;
          ret[i] = 0;
        } else {
          ret[i] = 1;
        }
      } else {
        count--;
        if (acount > 0) {
          acount--;
          ret[i] = 0;
        } else {
          ret[i] = 1;
        }
      }
    }
    return ret;
  }
}