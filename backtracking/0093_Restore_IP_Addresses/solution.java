package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
93. Restore IP Addresses

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]


 */
public class LC_0093_RestoreIPAddresses {
    /*
    https://www.youtube.com/watch?v=pi-S2TLYuL4

    time: O(3^4)=>O(1)  space: O(n)
     */
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();

        helper(res, s, 0, "", 0);

        return res;
    }

    public void helper(List<String> res, String s, int index, String ret, int count) {
        if (count > 4) {
            return;
        }
        if (count == 4 && index == s.length()) {
            res.add(ret);
            return;
        }
        for (int i = 1; i < 4; i++) {  //  取 1位，2位，3位
            if (index + i > s.length())
                break;

            String tmp = s.substring(index, index + i);
            if ((tmp.startsWith("0") && tmp.length() > 1) || (i == 3 && Integer.parseInt(tmp) >= 256))
                continue;

            helper(res, s, index + i, ret + tmp + (count == 3 ? "" : "."), count+1);
        }
    }
}
