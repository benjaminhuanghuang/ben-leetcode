/*
400. Nth Digit

Level: Medium

https://leetcode.com/problems/nth-digit
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
  int findNthDigit(int n)
  {
    // 开始时是一位数
    long long range_number_length = 1;
    // 开始时一位数有 9 个
    long long range = 9;     
    long long num = 1;

    while (n > range * range_number_length)
    {
      n -= range * range_number_length;
      ++range_number_length;

      num += range;   
      range *= 10;
    }
    //当n落到某一个确定的区间里了，那么(n-1)/len就是目标数字在该区间里的坐标，加上num就是得到了目标数字，
    // 然后我们将目标数字start转为字符串，(n-1)%len就是所要求的目标
    num += (n - 1) / range_number_length;
    return to_string(num).at((n - 1) % range_number_length) - '0';
  }
};