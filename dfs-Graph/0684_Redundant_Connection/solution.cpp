/*
684. Redundant Connection

https://leetcode.com/problems/redundant-connection/
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
https://zxi.mytechroad.com/blog/tree/leetcode-684-redundant-connection/
*/
class Solution_DFS {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            unordered_set<int> visited;
            if (hasPath(u, v, graph, visited))
                return edge;
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
private:
    bool hasPath(int curr, 
                 int goal, 
                 const unordered_map<int, vector<int>>& graph, 
                 unordered_set<int>& visited) {
        if (curr == goal) return true;
        visited.insert(curr);
        if (!graph.count(curr) || !graph.count(goal)) return false;
        for (int next : graph.at(curr)) {
            if (visited.count(next)) continue;
            if (hasPath(next, goal, graph, visited)) return true;
        }
        return false;
    }
};

#include "common/DSU.h"

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {    
        DSU s(edges.size());
        
        for(const auto& edge: edges)
            if (!s.Union(edge[0], edge[1]))  // The vertexes of this edge are already in save set.
                return edge;
        
        return {};
    }
};