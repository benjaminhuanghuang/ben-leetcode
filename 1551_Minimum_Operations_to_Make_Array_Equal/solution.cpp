/*
1551. Minimum Operations to Make Array Equal

Level: Medium

https://leetcode.com/problems/minimum-operations-to-make-array-equal
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
  https://leetcode.jp/leetcode-1551-minimum-operations-to-make-array-equal-%E8%A7%A3%E9%A2%98%E6%80%9D%E8%B7%AF%E5%88%86%E6%9E%90/
  Solution: 
*/

class Solution
{
public:
  int minOperations(int n)
  {
    int max = (n - 1) * 2 + 1;   // 最大值
    int average = (1 + max) / 2; // 平均值
    int res = 0;                 // 返回结果
    for (int i = 0; i < n / 2; i++)
    {                         // 循环数组前半部分
      int num = i * 2 + 1;    // 当前数字
      res += (average - num); // 将当前数字与平均值之差，累加至返回结果
    }
    return res;
  }
};