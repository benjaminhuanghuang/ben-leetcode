/*
743. Network Delay Time

https://leetcode.com/problems/network-delay-time/
*/

#include <string>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

/*
https://zxi.mytechroad.com/blog/graph/leetcode-743-network-delay-time/
*/
class Solution
{
public:
  int networkDelayTime(vector<vector<int>> &times, int N, int K)
  {
    constexpr int MAX_TIME = 101 * 100;
    vector<int> dist(N, MAX_TIME);
    dist[K - 1] = 0;
    for (int i = 1; i < N; ++i)
      for (const auto &time : times)
      {
        int u = time[0] - 1, v = time[1] - 1, w = time[2];
        dist[v] = min(dist[v], dist[u] + w);
      }
    int max_dist = *max_element(dist.begin(), dist.end());
    return max_dist == MAX_TIME ? -1 : max_dist;
  }
};