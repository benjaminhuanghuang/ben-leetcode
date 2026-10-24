package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
433. Minimum Genetic Mutation

A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as
ONE single character changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make
it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to
mutate from "start" to "end". If there is no such a mutation, return -1.

Note:

    Starting point is assumed to be valid, so it might not be included in the bank.
    If multiple mutations are needed, all mutations during in the sequence must be valid.
    You may assume start and end string is not the same.



Example 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1



Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2



Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3

 */

/*
    类似 Word Ladder
    广度优先搜索（BFS）
 */

public class LC_0433_MinimumGeneticMutation {
    public int minMutation(String start, String end, String[] bank) {
        List<List<String>> lists = new ArrayList<>();
        List<String> temp = new ArrayList<>();
        temp.add(start);
        lists.add(temp);
        for (int i = 0; i < lists.size(); i++) {
            List<String> list = lists.get(i);
            for (int j = 0; j < list.size(); j++) {
                String s = list.get(j);
                for (int k = 0; k < bank.length; k++) {
                    String s1 = bank[k];
                    if (Fit(s1, s)) {
                        if (s1.equals(end)) {
                            return i + 1;
                        }
                        if (!has(lists, s1)) {
                            if (i + 1 < lists.size()) {
                                lists.get(i + 1).add(s1);
                            } else {
                                temp = new ArrayList<>();
                                temp.add(s1);
                                lists.add(temp);
                            }
                        }
                    }
                }
            }
        }
        return -1;

    }

    private boolean has(List<List<String>> lists, String s1) {
        for (int i = 0; i < lists.size(); i++) {
            List<String> list = lists.get(i);
            if (list.contains(s1)) {
                return true;
            }
        }
        return false;
    }

    private boolean Fit(String s1, String s) {
        int count = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s.charAt(i)) {
                count++;
                if (count == 2) {
                    return false;
                }
            }
        }
        return true;
    }
}
