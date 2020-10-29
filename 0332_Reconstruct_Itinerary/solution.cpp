/*
332. Reconstruct Itinerary

https://leetcode.com/problems/reconstruct-itinerary/
*/
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
  vector<string> findItinerary(vector<vector<string>> &tickets)
  {
    vector<string> path;

    if(tickets.size() == 0)
      return path;

    int totalLen = tickets.size()+1;
    // Build graph
    unordered_map<string, vector<string>> graph;

    for (const auto &pair : tickets)
      graph[pair[0]].push_back(pair[1]);

    // traverse the graph/unordered_map
    for (auto &departure : graph)
    {
      auto &dests = departure.second;
      std::sort(dests.begin(), dests.end());
    }

    path.push_back("JFK");
    if(dfs("JFK", path, graph, totalLen))
    {
      return path;
    }
    return {};
  }

private:
  bool dfs(const string &start,vector<string>& path, unordered_map<string, vector<string>>& graph, int totalLen )
  {
    if(path.size() == totalLen)
    {
      return true;
    }
    if(graph.find(start) == graph.end())
    {
      return false;
    }
    vector<string>& destinaitons = graph[start];
    for(int i=0; i < destinaitons.size() ;i++)
    {
      string dest = destinaitons[i];
      destinaitons.erase(destinaitons.begin() + i);
      path.push_back(dest);
      if(dfs(dest, path, graph, totalLen)){
        return true;
      }
      path.pop_back();
      destinaitons.insert(destinaitons.begin() + i, dest);
    }
    return false;
  }
};

/*
https://zxi.mytechroad.com/blog/graph/leetcode-332-reconstruct-itinerary/
Time Complexity: O(n+e)
Space: O(n+e).
*/

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        _route.clear();
        _tripsGrpah.clear();
        // Build graph
        for (const auto &pair : tickets)
            _tripsGrpah[pair[0]].push_back(pair[1]);

        // traverse the graph/unordered_map
        for (auto &departure : _tripsGrpah)
        {
            auto &dests = departure.second;
            std::sort(dests.begin(), dests.end());
        }

        dfsVisit("JFK");
        //reversed
        return vector<string>(_route.crbegin(), _route.crend());
    }

private:
    unordered_map<string, deque<string>> _tripsGrpah;
    // ans (reversed)
    vector<string> _route;

    // 类似与 tree post-order traversal
    void dfsVisit(const string &src)
    {
        auto &dests = _tripsGrpah[src];
        while (!dests.empty())
        {
            // Get the smallest dest
            const string dest = dests.front();
            // Remove the ticket
            dests.pop_front();
            // Visit dest
            dfsVisit(dest);
        }
        // Add current node to the route
        _route.push_back(src);
    }
};

/*
    Using priority_queue
*/
class Solution2
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        _route.clear();
        _tripsGrpah.clear();
        // Build graph
        for (const auto &pair : tickets)
            _tripsGrpah[pair[0]].push(pair[1]);

        dfsVisit("JFK");
        //reversed
        return vector<string>(_route.crbegin(), _route.crend());
    }

private:
    //为了保证字母顺序，using PriorityQueue.
    // priority_queue默认排序是less，也就说大顶堆, 取值时是最大值。container 用 deque 比较快
    unordered_map<string, priority_queue<string, deque<string>, greater<string>>> _tripsGrpah;
    // ans (reversed)
    vector<string> _route;

    // 类似与 tree post-order traversal
    void dfsVisit(const string &src)
    {
        auto &dests = _tripsGrpah[src];
        while (!dests.empty())
        {
            // Get the smallest dest
            const string dest = dests.top();
            // Remove the ticket
            dests.pop();
            // Visit dest
            dfsVisit(dest);
        }
        // Add current node to the route
        _route.push_back(src);
    }
};