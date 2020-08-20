/*
218. The Skyline Problem []

https://leetcode.com/problems/the-skyline-problem/
*/

#include <vector>
#include <set>

using namespace std;

/*
  https://zxi.mytechroad.com/blog/tree/leetcode-218-the-skyline-problem/
*/
class Solution
{
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
  {
    // events,  x,   h
    vector<vector<int>> es;
    hs_.clear();

    for (const auto &b : buildings)
    {
      es.push_back({b[0], b[2]});
      es.push_back({b[1], -b[2]});
    }

    // Sort events by x
    sort(es.begin(), es.end(), [](const vector<int> &e1, const vector<int> &e2) {
      if (e1[0] == e2[0])
        return e1[1] > e2[1];
      return e1[0] < e2[0];
    });

    vector<vector<int>> ans;

    // Process all the events
    for (const auto &e : es)
    {
      int x = e[0];
      bool entering = e[1] > 0;
      int h = abs(e[1]);

      if (entering)
      {
        if (h > this->maxHeight())
          ans.push_back({x, h});
        hs_.insert(h);
      }
      else
      {
        hs_.erase(hs_.equal_range(h).first);
        if (h > this->maxHeight())
          ans.push_back({x, this->maxHeight()});
      }
    }

    return ans;
  }

private:
  int maxHeight() const
  {
    if (hs_.empty())
      return 0;
    return *hs_.rbegin();
  }
  multiset<int> hs_;
};