package cn.huang.leetcode;

import java.util.Arrays;
import java.util.Comparator;

/*
179. Largest Number
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"

Example 2:

Input: [3,30,34,5,9]
Output: "9534330"

 */
public class LC_0179_LargestNumber {
    public String largestNumber(int[] nums) {
        String num[] = new String[nums.length];
        if (nums == null || nums.length == 0) {
            return "";
        }
        for (int i = 0; i < nums.length; i++) {
            num[i] = String.valueOf(nums[i]);
        }

        Comparator<String> compr = new Comparator<String>() {
            public int compare(String a, String b) {
                String atob = a + b;
                String btoa = b + a;
                return btoa.compareTo(atob);   //
            }
        };
        Arrays.sort(num, compr);

        // Important
        if(num[0].charAt(0)=='0'){
            return "0";
        }

        StringBuilder rs = new StringBuilder();
        for (String x : num) {
            rs.append(x);
        }
        return rs.toString();
    }
}
