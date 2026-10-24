/*
57. Insert Interval

https://leetcode.com/problems/insert-interval/
*/
#include <vector>

using namespace std;

/*
  http://zxi.mytechroad.com/blog/geometry/leetcode-57-insert-interval/

  Find the position of the new interval, insert it into the list and merge intervals 
*/
class Solution
{
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
  {
    auto it = intervals.begin();
    while (it != intervals.end() && newInterval[0] > (*it)[0])
      ++it;
    intervals.insert(it, newInterval);

    // Merge intervals without sorting
    vector<vector<int>> ans;
    for (const auto &interval : intervals)
    {
      if (ans.empty() || interval[0] > ans.back()[1])
      {
        // no overlap
        ans.push_back(interval);
      }
      else
      {
        //merge to the last one
        ans.back()[1] = max(ans.back()[1], interval[1]);
      }
    }

    return ans;
  }
};