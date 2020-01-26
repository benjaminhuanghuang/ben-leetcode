package cn.huang.leetcode;

import java.util.HashSet;
import java.util.List;

/*
841. Keys and Rooms

 */
public class LC_0841_KeysandRooms {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        if (rooms == null)
            return false;

        HashSet<Integer> visited = new HashSet<>();
        dfs(rooms, 0, visited);

        return visited.size() == rooms.size();

    }

    private void dfs(List<List<Integer>> rooms, int curr, HashSet<Integer> visited )
    {
        if(visited.contains(curr))
        {
            return;
        }
        visited.add(curr);
        for(int next: rooms.get(curr))
        {
            dfs(rooms, next, visited);
        }
    }
}
