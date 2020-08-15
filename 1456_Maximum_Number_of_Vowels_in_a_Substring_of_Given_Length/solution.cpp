/*
1456. Maximum Number of Vowels in a Substring of Given Length

Level: Medium

https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length
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
  Solution: Sliding Window
*/

class Solution
{
public:
  int maxVowels(string s, int k)
  {
    vector<int> v(128);
    v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = 1;
    int total = 0;
    int ans = 0;
    for (int i = 1; i <= s.length(); ++i)
    {
      total += v[s[i - 1]];
      if (i >= k)
      {
        ans = max(ans, total);
        total -= v[s[i - k]];
      }
    }
    return ans;
  }
};