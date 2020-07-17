/*
201. Bitwise AND of Numbers Range

Level: Medium

https://leetcode.com/problems/bitwise-and-of-numbers-range
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
  等价于 求 m 与 n 二进制编码中 两者最高位的那些1 形成的数字.
  最高位1 后面的各位，在AND运算的结果为0
*/

class Solution
{
public:
  int rangeBitwiseAnd(int m, int n)
  {
    int bit = 0;
    while (m != n)
    {
      m >> 1;
      n >> 1;
      bit++;
    }
    return m << bit;
  }
};