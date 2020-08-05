/*
738. Monotone Increasing Digits

Level: Medium

https://leetcode.com/problems/monotone-increasing-digits
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
  int monotoneIncreasingDigits(int N)
  {
    string str = to_string(N);
    int n = str.size(), j = n;
    for (int i = n - 1; i > 0; --i)
    {
      if (str[i] >= str[i - 1])
        continue;
      --str[i - 1];
      j = i;
    }
    for (int i = j; i < n; ++i)
    {
      str[i] = '9';
    }
    return stoi(str);
  }
};