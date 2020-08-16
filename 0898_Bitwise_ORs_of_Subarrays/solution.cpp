/*
898. Bitwise ORs of Subarrays

Level: Medium

https://leetcode.com/problems/bitwise-ors-of-subarrays
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
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-898-bitwise-ors-of-subarrays/
*/

class Solution
{
public:
  int subarrayBitwiseORs(vector<int> &A)
  {
    unordered_set<int> ans;
    unordered_set<int> cur;
    unordered_set<int> nxt;
    for (int a : A)
    {
      nxt.clear();
      nxt.insert({a});
      for (int b : cur)
      {
        nxt.insert(a | b);
      }
      cur.swap(nxt);
      ans.insert(begin(cur), end(cur));
    }
    return ans.size();
  }
};