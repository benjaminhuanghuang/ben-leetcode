/*
1540. Can Convert String in K Moves

Level: Medium

https://leetcode.com/problems/can-convert-string-in-k-moves
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
  https://www.youtube.com/watch?v=weZYtqRqMO8
*/

class Solution
{
public:
  bool canConvertString(string s, string t, int k)
  {
    if (s.length() != t.length())
      return false;
    vector<int> count(26);  // range of move: 1 to 26
    for (int i = 0; i < s.length(); ++i)
    {
      int d = (t[i] - s[i] + 26) % 26;
      int c = count[d]++;
      if (d != 0 && d + c * 26 > k)
        return false;
    }
    return true;
  }
};