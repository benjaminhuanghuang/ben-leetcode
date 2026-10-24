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
  string makeGood(string s)
  {
    string ans;
    for (char c : s)
    {
      if (ans.length() &&
          abs(ans.back() - c) == 'a' - 'A')
        ans.pop_back();
      else
        ans.push_back(c);
    }
    return ans;
  }
};