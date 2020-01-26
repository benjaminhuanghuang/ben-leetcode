package cn.huang.leetcode;

import java.util.*;

/*
332. Reconstruct Itinerary

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to],
reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK.
Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical
order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
 */

/*
 用光所有的票，
 */
public class LC_0332_ReconstructItinerary {
    //为了保证字母顺序，用了PriorityQueue.
    HashMap<String, PriorityQueue<String>> graph = new HashMap<String, PriorityQueue<String>>();
    LinkedList<String> result = new LinkedList<String>();


    public List<String> findItinerary(String[][] tickets) {
        // add ticket into graph
        for (String[] ticket : tickets) {
            if (!graph.containsKey(ticket[0])) {
                PriorityQueue<String> q = new PriorityQueue<String>();
                graph.put(ticket[0], q);
            }
            graph.get(ticket[0]).offer(ticket[1]);
        }

        dfs("JFK");
        return result;

    }

    public void dfs(String start) {
        PriorityQueue<String> ends = graph.get(start);

        while (ends != null && !ends.isEmpty()) {
            dfs(ends.poll());
        }

        result.addFirst(start);
    }
}
