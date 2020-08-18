/*
1419. Minimum Number of Frogs Croaking

Level: Medium

https://leetcode.com/problems/minimum-number-of-frogs-croaking
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://zxi.mytechroad.com/blog/hashtable/leetcode-1419-minimum-number-of-frogs-croaking/

  Count the frequency of the letters, we need to make sure f[c] >= f[r] >= f[o] >= f[a] >= f[k] holds all the time, otherwise return -1.
  whenever encounter c, increase the current frog, whenever there is k, decrease the frog count.
  Don’t forget to check the current frog number, should be 0 in the end, otherwise there are open letters.

  Time complexity: O(n)
  Space complexity: O(1)
*/

class Solution
{
public:
  int minNumberOfFrogs(string croakOfFrogs)
  {
    vector<int> idx(26);
    idx['c' - 'a'] = 0;
    idx['r' - 'a'] = 1;
    idx['o' - 'a'] = 2;
    idx['a' - 'a'] = 3;
    idx['k' - 'a'] = 4;
    vector<int> count(5);
    int cur = 0;
    int ans = 0;
    for (char ch : croakOfFrogs)
    {
      const int i = idx[ch - 'a'];
      ++count[i];
      if (ch == 'c')
      {
        ans = max(ans, ++cur);
        continue;
      }
      if (count[i] > count[i - 1])
        return -1;
      if (ch == 'k')
        --cur;
    }
    return cur ? -1 : ans;
  }
};