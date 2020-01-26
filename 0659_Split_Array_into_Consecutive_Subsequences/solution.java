package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.PriorityQueue;

/*
659. Split Array into Consecutive Subsequences

You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several
subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

Example 1:

Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences :
1, 2, 3
3, 4, 5

Example 2:

Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences :
1, 2, 3, 4, 5
3, 4, 5

Example 3:

Input: [1,2,3,4,4,5]
Output: False

Note:

    The length of the input is in range of [1, 10000]

 */
public class LC_0659_SplitArrayintoConsecutiveSubsequences {
    /*
    http://bookshadow.com/weblog/2017/08/13/leetcode-split-array-into-consecutive-subsequences/
    Map + PriorityQueue

    思路类似于排列扑克牌，优先将数字排在长度较小的扑克牌队列后面

    Map<Integer, PriorityQueue<Integer>> dmap的key为扑克牌队列的末尾，value为优先队列，存储扑克牌队列的长度
     */
    private HashMap<Integer, PriorityQueue<Integer>> dmap = new HashMap<>();

    public boolean isPossible(int[] nums) {
        for (int num : nums) {
            PriorityQueue<Integer> pq0 = getOrPut(num - 1);
            int len = pq0.isEmpty() ? 0 : pq0.poll();
            PriorityQueue<Integer> pq1 = getOrPut(num);
            pq1.offer(len + 1);
        }

        for (int key : dmap.keySet()) {
            for (int len : dmap.get(key)) {
                if (len < 3) return false;
            }
        }
        return true;
    }

    public PriorityQueue<Integer> getOrPut(int num) {
        PriorityQueue<Integer> pq = dmap.get(num);
        if (pq == null) {
            pq = new PriorityQueue<Integer>();
            dmap.put(num, pq);
        }
        return pq;
    }


    public boolean isPossible2(int[] nums) {
        if (nums == null || nums.length < 3) {
            return false;
        }
        List<List<Integer>> subsequences = new ArrayList<>();
        for (int num : nums) {
            if (subsequences.isEmpty()) {
                List<Integer> subsequence = new ArrayList<>();
                subsequence.add(num);
                subsequences.add(subsequence);
            } else {
                boolean inserted = false;
                List<Integer> firstSubsequence = null;
                for (List<Integer> subsequence : subsequences) {
                    if (subsequence.get(subsequence.size() - 1) == num - 1) {
                        if(null == firstSubsequence){
                            firstSubsequence = subsequence;
                        }
                        if(subsequence.size() < 3) {
                            subsequence.add(num);
                            inserted = true;
                            break;
                        }
                    }
                    if (subsequence.get(subsequence.size() - 1) < num - 1 && subsequence.size() < 3){
                        return false;
                    }
                }
                if (!inserted && firstSubsequence != null) {
                    firstSubsequence.add(num);
                    inserted = true;
                }
                if (!inserted) {
                    List<Integer> subsequence = new ArrayList<>();
                    subsequence.add(num);
                    subsequences.add(subsequence);
                }
            }
        }
        for (List<Integer> subsequence : subsequences) {
            if (subsequence.size() < 3) {
                return false;
            }
        }
        return true;
    }
}
