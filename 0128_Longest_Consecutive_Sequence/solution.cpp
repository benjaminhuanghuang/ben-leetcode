
/*
  
*/

#include <vector>
#include <unordered_map>
#include <assert.h> /* assert */

using namespace std;

class Solution
{
public:
  int longestConsecutive(vector<int> &num)
  {
    unordered_map<int, int> m;
    int ans = 0;
    for (auto n : num)
    {
      if (m.count(n))
        continue;
      if (m.count(n - 1) && m.count(n + 1))
      {
        int l = m[n - 1], r = m[n + 1];
        m[n] = m[n - l] = m[n + r] = r + l + 1;
      }
      else if (m.count(n - 1))
      {
        int l = m[n - 1];
        m[n] = m[n - l] = l + 1;
      }
      else if (m.count(n + 1))
      {
        int r = m[n + 1];
        m[n] = m[n + r] = r + 1;
      }
      else
      {
        m[n] = 1;
      }
      ans = max(ans, m[n]);
    }
    return ans;
  }
};
