package cn.huang.leetcode;

import java.util.*;

/*
839. Similar String Groups

Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list A of strings.  Every string in A is an anagram of every other string in A.  How many groups are there?

Example 1:

Input: ["tars","rats","arts","star"]
Output: 2

Note:

    A.length <= 2000
    A[i].length <= 1000
    A.length * A[i].length <= 20000
    All words in A consist of lowercase letters only.
    All words in A have the same length and are anagrams of each other.
    The judging time limit has been increased for this question.


 */
public class LC_0839_SimilarStringGroups {
    public int numSimilarGroups(String[] A) {
        if (A == null || A.length == 0) return 0;
        Set<String> set = new HashSet<>(Arrays.asList(A));
        Queue<String> q = new LinkedList<>();

        int count = 0;
        for (String s : A) {
            if (set.contains(s)) {
                count++;
                q.offer(s);
                set.remove(s);

                while (!q.isEmpty()) {
                    String tmp = q.poll();
                    List<String> list = new ArrayList<>(set);
                    for (String n : list) {
                        int diff = 0;
                        for (int i = 0; i < n.length(); i++) {
                            if (tmp.charAt(i) != n.charAt(i)) diff++;
                        }
                        if (diff == 2) {
                            q.offer(n);
                            set.remove(n);
                        }
                    }
                }
            }
        }
        return count;
    }
}
