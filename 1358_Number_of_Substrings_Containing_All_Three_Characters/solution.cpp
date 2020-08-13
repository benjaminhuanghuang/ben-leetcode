/*
1358. Number of Substrings Containing All Three Characters

Level: Medium

https://leetcode.com/problems/number-of-substrings-containing-all-three-characters
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
  https://zxi.mytechroad.com/blog/string/1358-number-of-substrings-containing-all-three-characters/
*/

class Solution
{
public:
  int numberOfSubstrings(string s)
  {
    vector<int> l{-1, -1, -1};
    int ans = 0;
    for (size_t i = 0; i < s.length(); ++i)
    {
      l[s[i] - 'a'] = i;
      ans += 1 + *min_element(begin(l), end(l));
    }
    return ans;
  }
};

/*
  [j, i] sliding window
*/
class Solution
{
public:
  int numberOfSubstrings(string s)
  {
    vector<int> counter{0, 0, 0};
    int ans = 0;
    int j = 0;
    for (size_t i = 0; i < s.length(); ++i)
    {
      counter[s[i] - 'a']++;
      while (j < i && counter[0] > 0 && counter[1] > 0 && counter[2] > 0)
      {
        counter[s[j] - 'a']--;
        j++;
      }
      ans += j;
    }
    return ans;
  }
};