/*
504. Base 7

Level: Easy

https://leetcode.com/problems/base-7
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
  string convertToBase7(int num)
  {
    if (num == 0)
      return "0";

    string res = "";
    bool isNegative = num < 0;
    if (isNegative)
      num = -num;

    while (num > 0)
    {
      res = to_string(num % 7) + res;
      num = num / 7;
    }

    if (isNegative)
      res = "-" + res;
    return res;
  }
};