/*
438. Find All Anagrams in a String

Level: Medium

https://leetcode.com/problems/find-all-anagrams-in-a-string
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  http://zxi.mytechroad.com/blog/hashtable/leetcode-438-find-all-anagrams-in-a-string/

  HashTable + Sliding Window

  Time complexity: O(n)

  Space complexity: O(n)
*/

class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    int n = s.length();
    int l = p.length();
    vector<int> ans;
    vector<int> vp(26, 0);
    vector<int> vs(26, 0);
    for (char c : p)
      ++vp[c - 'a'];
    for (int i = 0; i < n; ++i)
    {
      if (i >= l)
        --vs[s[i - l] - 'a'];
      ++vs[s[i] - 'a'];
      if (vs == vp)  // deep equal
        ans.push_back(i + 1 - l);
    }
    return ans;
  }
};