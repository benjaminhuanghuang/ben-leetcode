/*
1405. Longest Happy String

Level: Medium

https://leetcode.com/problems/longest-happy-string

# 984
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
  Put the char with highest frequency first if its consecutive length of that char is < 2
  or put one char if any of other two chars has consecutive length of 2.

  increase the consecutive length of itself and reset that for other two chars.

  Time complexity: O(n)
  Space complexity: O(1)


*/

class Solution
{
public:
  string longestDiverseString(int a, int b, int c)
  {
    const int total = a + b + c;
    vector<int> f{a, b, c};
    vector<int> l{0, 0, 0};
    string ans;
    for (int _ = 0; _ < total; ++_)
      for (int i = 0; i < 3; ++i)
      {
        const int j = (i + 1) % 3;
        const int k = (i + 2) % 3;
        if ((f[i] >= f[j] && f[i] >= f[k] && l[i] != 2) || (f[i] > 0 && (l[j] == 2 || l[k] == 2)))
        {
          ans += 'a' + i;
          ++l[i];
          --f[i];
          l[j] = l[k] = 0;
          break;
        }
      }
    return ans;
  }
};