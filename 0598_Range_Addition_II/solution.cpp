/*
598. Range Addition II

Level: Easy

https://leetcode.com/problems/range-addition-ii
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
  找出ops中[row, col] 的交集
*/

class Solution
{
public:
  int maxCount(int m, int n, vector<vector<int>> &ops)
  {
    int minRow = m, minCol = n;
    for (int i = 0; i < ops.size(); i++)
    {
      if (ops[i][0] != 0 && ops[i][0] < minRow)
      {
        minRow = ops[i][0];
      }
      if (ops[i][1] != 0 && ops[i][1] < minCol)
      {
        minCol = ops[i][1];
      }
    }
    return minRow * minCol;
  }
};