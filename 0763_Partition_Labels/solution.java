package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
763. Partition Labels
A string S of lowercase letters is given. We want to partition this string into as many parts as possible
so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

 */
public class LC_0763_PartitionLabels {
    /*
    把字符串分割成尽量多的不重叠子串，输出子串的长度数组。要求相同字符只能出现在一个子串中。
    https://zxi.mytechroad.com/blog/string/leetcode-763-partition-labels/
     */
    public List<Integer> partitionLabels(String S) {
        int lastIndex[] = new int[128];  // last index of each char
        for (int i = 0; i < S.length(); ++i)
            lastIndex[(int) S.charAt(i)] = i;

        List<Integer> ans = new ArrayList<>();
        int start = 0;
        int end = 0;
        for (int i = 0; i < S.length(); ++i) {
            end = Math.max(end, lastIndex[(int) S.charAt(i)]);
            if (i == end) {
                ans.add(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
}
