/*
1203. Sort Items by Groups Respecting Dependencies

Level: Hard

https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies
*/
package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
  Solution: 

  https://www.youtube.com/watch?v=nE97bUETsCM

  1. topoligical sort items.
  2. topolobical srot group
  3. put sorted items to its group with the output of step 1 and 2
  4. iterate gropu in order and add items in each boutp to the result array
*/
class Solution {
  public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {

  }

  public List<Integer> tpSort(HashMap<Integer, List<Integer>> graph, int[] inDegree, int count) {
    List<Integer> ans = new ArrayList<>();

    Queue<Integer> q = new LinkedList<>();

    for (int i = 0; i < inDegree.length; i++) {
      if (inDegree[i] == 0) {
        q.offer(i);
      }
    }
    while (!q.isEmpty()) {
      int cur = q.poll();
      ans.add(cur);
      if (graph.containsKey(cur)) {
        for (int next : graph.get(cur)) {
          inDegree[next]--;
          if (inDegree[next] == 0) {
            q.offer(next);
          }
        }
      }
    }

    return count == ans.size() ? ans : new ArrayList<>();
  }
}