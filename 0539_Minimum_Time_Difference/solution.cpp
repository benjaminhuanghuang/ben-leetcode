/*
539. Minimum Time Difference

https://leetcode.com/problems/minimum-time-difference/
*/

#include <string>
#include <vector>
#include <set>
using namespace std;

/*
https://zxi.mytechroad.com/blog/string/leetcode-539-minimum-time-difference/
Time complexity: O(nlog1440)
Space complexity: O(n)
*/
class Solution
{
public:
  int findMinDifference(vector<string> &timePoints)
  {
    constexpr int kMins = 24 * 60;
    set<int> seen;
    for (const string &time : timePoints)
    {
      int m = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
      if (!seen.insert(m).second) // duplicated time
        return 0;
    }

    int ans = (*seen.begin() - *seen.rbegin() + kMins) % kMins;
    const int *l = nullptr;
    for (const int &t : seen)
    {
      if (l)
        ans = min(ans, t - *l);
      l = &t;
    }
    return ans;
  }
};

/*
https://www.cnblogs.com/grandyang/p/6568398.html

Time complexity: O(nl)
Space complexity: O(n)
*/
class Solution
{
public:
  int findMinDifference(vector<string> &timePoints)
  {
    int res = INT_MAX, pre = 0, first = INT_MAX, last = INT_MIN;
    vector<int> mask(1440, 0);
    for (string str : timePoints)
    {
      int h = stoi(str.substr(0, 2)), m = stoi(str.substr(3));
      if (mask[h * 60 + m] == 1)   // find duplicate time
        return 0;
      mask[h * 60 + m] = 1;
    }
    for (int i = 0; i < 1440; ++i)
    {
      if (mask[i] == 1)
      {
        if (first != INT_MAX)
        {
          res = min(res, i - pre);
        }
        first = min(first, i);
        last = max(last, i);
        pre = i;
      }
    }
    return min(res, 1440 + first - last);
  }
};
