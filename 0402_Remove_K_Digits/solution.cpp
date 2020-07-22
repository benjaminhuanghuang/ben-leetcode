/*
402. Remove K Digits

Level: Medium

https://leetcode.com/problems/remove-k-digits
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
  数字尽可能保持递增顺序。
    // 需要注意的是字符串首字符不为０
*/

class Solution
{
public:
  string removeKdigits(string num, int k)
  {
    if (k >= num.size())
      return "0";
    string s = num;
    int i, j;
    for (i = 0; i < k; i++)
    {
      j = 0;
      while (j < s.size() - 1)
      {
        if (s[j] > s[j + 1])
          break;
        j++;
      }
      s.erase(j, 1); // remove string at j, length = j + 1;
    }
    while (s.size() > 1 && s[0] == '0')
      s.erase(0, 1);
    return s;
  }
};