/*
397. Integer Replacement

Level: Medium

https://leetcode.com/problems/integer-replacement
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
  当n为偶数时，下一次迭代n的取值确定为n / 2；

  当n为奇数时，下一次迭代n的取值n + 1或者n - 1，由其二进制表示中的最低两位数决定：

  若n的最低两位数为01，则令n = n - 1

  否则，若n的最低两位数为11，则令n = n + 1

  这样处理是为了使n的二进制表式中1的数目尽可能少，从而减少迭代次数
*/

class Solution
{
public:
  int integerReplacement(int n)
  {
    int op = 0;
    if (n == 3)
      return 2;
    long long n1 = n;
    while (n1 > 1)
    {
      if (n1 % 2 == 0)
        n1 /= 2;
      else
      {
        long long int t = (n1 - 1) / 2;
        if (t % 2 == 0)
          n1 -= 1;
        else
          n1 += 1;
      }
      if (n1 == 3)
        return n1 + op;
      op++;
    }
    return op;
  }
};