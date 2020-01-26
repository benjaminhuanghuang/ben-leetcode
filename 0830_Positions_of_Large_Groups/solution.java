package cn.huang.leetcode;

/*
	830	 Positions of Large Groups
 */

import java.util.ArrayList;
import java.util.List;

public class LC_0830_PositionsofLargeGroups {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> res = new ArrayList<>();

        char currChar = S.charAt(0);
        int start = 0;
        int end = 0;

        for (int i = 1; i < S.length(); i++) {
            if (S.charAt(i) == currChar) {
                end++;
                if (i == S.length() - 1 && end - start + 1 >= 3) {
                    ArrayList<Integer> item = new ArrayList<>();
                    item.add(start);
                    item.add(end);
                    res.add(item);
                }
            } else {
                currChar = S.charAt(i);
                if (end - start + 1 >= 3) {
                    ArrayList<Integer> item = new ArrayList<>();
                    item.add(start);
                    item.add(end);
                    res.add(item);
                }
                start = i;
                end = i;
            }
        }
        return res;
    }

    public List<List<Integer>> largeGroupPositions_Better(String S) {
        List<List<Integer>> res = new ArrayList<>();

        char currChar = S.charAt(0);
        int start = 0;

        int i = 1;
        for (; i < S.length(); i++) {
            if (S.charAt(i) != currChar) {
                if (i - start >= 3) {
                    ArrayList<Integer> item = new ArrayList<>();
                    item.add(start);
                    item.add(i - 1);
                    res.add(item);
                }
                currChar = S.charAt(i);
                start = i;
            }
        }
        if (i - start >= 3) {
            ArrayList<Integer> item = new ArrayList<>();
            item.add(start);
            item.add(i - 1);
            res.add(item);
        }
        return res;
    }
}
