/*
1209. Remove All Adjacent Duplicates in String II

Level: Medium

https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii
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
  string removeDuplicates(string s, int k)
  {
    vector<pair<char, int>> st{{'*', 0}};

    for (char c : s)
      if (c != st.back().first)
        st.emplace_back(c, 1);
      else if (++st.back().second == k)
        st.pop_back();
    
    string ans;
    for (const auto &p : st)
      ans.append(p.second, p.first);
    return ans;
  }
};