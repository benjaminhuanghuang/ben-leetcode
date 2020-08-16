/*
1234. Replace the Substring for Balanced String

Level: Medium

https://leetcode.com/problems/replace-the-substring-for-balanced-string
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
  https://www.tutorialspoint.com/replace-the-substring-for-balanced-string-in-cplusplus
*/

class Solution
{
public:
  int balancedString(string s)
  {
    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); i++)
      m[s[i]]++;
    int n = s.size();
    int res = n;
    int left = 0;
    for (int right = 0; right < n; right++)
    {
      m[s[right]]--;
      while (left < n && m['Q'] <= n / 4 && m['W'] <= n / 4 && m['E'] <= n / 4 && m['R'] <= n / 4)
      {
        res = min(res, right - left + 1);
        m[s[left]] += 1;
        left++;
      }
    }
    return res;
  }
};