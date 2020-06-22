/*
405. Convert a Number to Hexadecimal

Level: Easy

https://leetcode.com/problems/convert-a-number-to-hexadecimal
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
*/

class Solution
{
public:
  string toHex(int num)
  {
    string res = "";
    // 有符号数右移， 左边会补上符号位 Note:  i < 8
    for (int i = 0; num != 0 && i < 8; ++i)
    {
      int t = num & 0xf;
      if (t >= 10)
        res = (char)('a' + t - 10) + res;
      else
        res = (char)('0' + t) + res;
      num >>= 4;
    }
    return res == "" ? "0" : res;
  }
};