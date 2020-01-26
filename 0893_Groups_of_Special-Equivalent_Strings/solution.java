package cn.huang.leetcode;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/*
	893	 Groups of Special-Equivalent Strings

    You are given an array A of strings.

    Two strings S and T are special-equivalent if after any number of moves, S == T.

    A move consists of choosing two indices i and j with i % 2 == j % 2, and swapping S[i] with S[j].

    Now, a group of special-equivalent strings from A is a non-empty subset S of A such that any string not in S is not special-equivalent with any string in S.

    Return the number of groups of special-equivalent strings from A.



    Example 1:

    Input: ["a","b","c","a","c","c"]
    Output: 3
    Explanation: 3 groups ["a","a"], ["b"], ["c","c","c"]
 */
public class LC_0893_GroupsofSpecialEquivalentStrings {
    public int numSpecialEquivGroups(String[] A) {
        Set<String> groups = new HashSet<>();
        for (String s : A) {
            int[] m1 = new int[256];
            int[] m2 = new int[256];
            for (int i = 0; i < s.length(); i++) {
                if (i % 2 == 0)
                    m1[s.charAt(i)]++;
                else
                    m2[s.charAt(i)]++;
            }
            groups.add(Arrays.toString(m1) + Arrays.toString(m2));
        }
        return groups.size();
    }

    public int numSpecialEquivGroups_V2(String[] A) {
        Set<String> groups = new HashSet<>();
        for (String a : A) {
            char[] odd = new char[(a.length() + 1) / 2];
            char[] even = new char[(a.length() + 1) / 2];
            for (int i = 0; i < a.length(); ++i) {
                if (i % 2 == 0)
                    even[i / 2] = a.charAt(i);
                else
                    odd[i / 2] = a.charAt(i);
            }
            Arrays.sort(odd);
            Arrays.sort(even);
            String s = new String(odd) + new String(even);
            groups.add(s);
        }
        return groups.size();
    }
}
