package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*

886. Possible Bipartition

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group.

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.



Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]

Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false



Note:

    1 <= N <= 2000
    0 <= dislikes.length <= 10000
    1 <= dislikes[i][j] <= N
    dislikes[i][0] < dislikes[i][1]
    There does not exist i != j for which dislikes[i] == dislikes[j].


 */
public class LC_0886_PossibleBipartition {
    /*
    https://www.youtube.com/watch?v=VlZiMD7Iby4
    分成两组，图染色
     */
    public boolean possibleBipartition(int N, int[][] dislikes) {
        // build graph , key : current, value : a list of nei
        // color them
        int[] visited = new int[N + 1];
        // 0 : not visited, 1: red. 2 : black

        List<List<Integer>> graph = new ArrayList<>();

        for(int i = 0; i <= N; i++){
            graph.add(new ArrayList<>());
        }
        // fill int the graph with infor from dislikes
        for(int[] pair : dislikes){
            int cur = pair[0];
            int nei = pair[1];
            graph.get(cur).add(nei);
            graph.get(nei).add(cur);
        }

        for(int i = 1; i <= N; i++){
            if(visited[i] == 0 && !bfs(graph, i, visited)){
                return false;
            }
        }
        return true;
    }


    private boolean bfs(List<List<Integer>> graph, int i, int[] visited){
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(i);
        visited[i] = 1;
        while(!queue.isEmpty()){
            int current = queue.poll();
            for(int nei : graph.get(current)){
                if(visited[nei] == 0){
                    visited[nei] = visited[current] == 1 ? 2 : 1;
                    queue.offer(nei); // don't forget to offer to the queue
                }else{
                    if(visited[nei] == visited[current]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
