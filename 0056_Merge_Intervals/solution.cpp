/*
56. Merge Intervals

https://leetcode.com/problems/merge-intervals/
*/
#include <vector>

using namespace std;

/*
http://zxi.mytechroad.com/blog/geometry/leetcode-56-merge-intervals/

Time complexity O(NlogN)
Space complexity O(N)
*/
class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    if (intervals.empty())
      return {};
    // sort by start
    std::sort(intervals.begin(), intervals.end(),
              [](const vector<int> &a, const vector<int> &b) {
                return a[0] < b[0];
              });

    vector<vector<int>> ans;
    for (const auto &interval : intervals)
    {
      if (ans.empty() || interval[0] > ans.back()[1])
      {
        ans.push_back(interval);
      }
      else
      {
        // merge to last one, expend the end of ans.bakc()s
        ans.back()[1] = max(ans.back()[1], interval[1]);
      }
    }

    return ans;
  }
};