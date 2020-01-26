package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/*
187. Repeated DNA Sequences

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]


 */
public class LC_0187_RepeatedDNASequences {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> res = new ArrayList<>();
        HashMap<String, Integer> map = new HashMap<String, Integer>();

        for (int index = 10; index <= s.length(); index++) {
            // 从第10位开始作为结尾，位移一位，比较一次子串
            String substr = s.substring(index - 10, index);   // key point
            if (map.containsKey(substr)) {
                // 如果是第一次遇到，则加入结果
                if (map.get(substr) == 1) {
                    res.add(substr);
                }
                // 标记为已经遇到过一次了
                map.put(substr, 2);
            } else {
                // 如果不存在，则加入表中
                map.put(substr, 1);
            }
        }

        return res;
    }
}
