/*
858. Mirror Reflection

Level: Medium

https://leetcode.com/problems/mirror-reflection
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
  https://buptwc.com/2018/06/26/Leetcode-858-Mirror-Reflection/
*/

class Solution
{
public:
  int mirrorReflection(int p, int q)
  {
    // 先找到第一个横坐标为p的倍数的点
    int k = 1;
    while (p * k % q != 0)
      k += 1;

    //若为x的偶数倍
    if (k % 2 == 0)
      return 0;
    else
    {
      // 分别判断p的奇数倍和偶数倍
      int r = p * k / q;
      if (r % 2 == 1)
        return 1;
      else
        return 2;
    }
  }
};