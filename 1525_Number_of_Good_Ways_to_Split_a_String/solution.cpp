/*
1525. Number of Good Ways to Split a String

Level: Medium

https://leetcode.com/problems/number-of-good-ways-to-split-a-string
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
*/

class Solution
{
public:
  int numSplits(string s)
  {
    // char counter for left part and right part
    vector<int> r(26);
    vector<int> l(26);
    int distinct_r = 0;     // number of distinct chars in right part
    for (char c : s)
    {
      r[c - 'a']++;
      if (r[c - 'a']==1)
      {
        distinct_r++;
      }
    }
      
    int ans = 0;
    int distinct_l = 0;
    for (char c : s)
    {
      l[c - 'a']++;
      r[c - 'a']--;
      if(l[c - 'a'] == 1)
      {
        distinct_l++;
      }
      if(r[c - 'a'] == 0){
        distinct_r--;
      }
      ans += distinct_l == distinct_r;
    }
    return ans;
  }
};