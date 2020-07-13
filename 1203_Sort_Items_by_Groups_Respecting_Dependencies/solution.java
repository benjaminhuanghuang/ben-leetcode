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
    HashMap<Integer, List<Integer>> gGraph = new HashMap<>();
    HashMap<Integer, List<Integer>> iGraph = new HashMap<>();

    // item items do not belong to group to new group
    for(int i=0; i< group.length; i++){
      if(group[i] == -1)
      {
        // i-th item belongs to no group
        group[i] = m++; 
      }
    }

    int[] itemInDegree = new int[n];
    int[] groupInDegree = new int[m];     // m is increased abrove.

    // build item graph
    for(int  to =0; to < beforeItems.size(); to ++)
    {
      int toGroup = group[to];

      for(int from: beforeItems.get(to)){
        itemInDegree[to]++;
        if(!iGraph.containsKey(from))
        {
          iGraph.put(from, new ArrayList<Integer>());
        }
        iGraph.get(from).add(to);
      }
    }
    // build group graph
    for(int  to =0; to < group.length; to++)
    {
      int toGroup = group[to];

      for(int from: beforeItems.get(to)){
        int fromGroup = group[to];
        if(!gGraph.containsKey(from))
        {
          gGraph.put(fromGroup, new ArrayList<Integer>());
        }
       if(fromGroup != toGroup){
          groupInDegree[toGroup]++;
          gGraph.get(fromGroup).add(to);
        }
      }
    }

    List<Integer> iList = tpSort(iGraph, itemInDegree, n);
        List<Integer> gList = tpSort(gGraph, groupInDegree, n);


    if(iList.size() == 0 || gList.size() ==0)
      return new int[0];


    HashMap<Integer, List<Integer>> groupedList = new HashMap<>();
    
    for(int item : iList){
      int grp = group[item];
      if(!groupedList.containsKey(grp))
      {
        groupedList.put(grp, new ArrayList<Integer>());
      }
      groupedList.get(grp).add(item);
    }

    int i =0 ;
    int[] ans = new int[0];
    for(int grp: gList){
      if(groupedList.containsKey(grp))
      {
        for(int item: groupedList.get(grp)){
          ans[i] = item;
          i++;
        }
      }
    }
    return ans;
  }

  public List<Integer> tpSort(HashMap<Integer, List<Integer>> graph, int[] inDegree, int count){
    List<Integer> ans = new ArrayList<>();

    Queue<Integer> q=new LinkedList<>();

    for(int i =0; i < inDegree.length; i++){
      if (inDegree[i] == 0){
        q.offer(i);
      }
    }
    while(!q.isEmpty()){
      int cur = q.poll();
      ans.add(cur);
      if(graph.containsKey(cur)){
        for(int next: graph.get(cur)){
          inDegree[next]--;
          if(inDegree[next] ==0){
            q.offer(next);
          }
        }
      }
    }

    return count == ans.size() ? ans : new ArrayList<>();
  }
} 