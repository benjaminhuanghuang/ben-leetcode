/*
1371. Find the Longest Substring Containing Vowels in Even Counts

Level: Medium

https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts
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
  https://zxi.mytechroad.com/blog/hashtable/leetcode-1371-find-the-longest-substring-containing-vowels-in-even-counts/

  Solution: prefix

*/

class Solution
{
public:
  int findTheLongestSubstring(string s)
  {
    const char vowels[] = "aeiou";
    vector<int> idx(1 << 5, INT_MAX); // state -> first_index
    idx[0] = -1;
    int state = 0;
    int ans = 0;
    for (int i = 0; i < s.length(); ++i)
    {
      for (int j = 0; j < 5; ++j)
        if (s[i] == vowels[j])
          state ^= 1 << j;
      if (idx[state] == INT_MAX)
        idx[state] = i;
      ans = max(ans, i - idx[state]);
    }
    return ans;
  }
};