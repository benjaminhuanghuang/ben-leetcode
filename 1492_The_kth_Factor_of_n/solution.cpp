/*
1492. The kth Factor of n

Level: Medium

https://leetcode.com/problems/the-kth-factor-of-n
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
  https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1492-the-kth-factor-of-n/
*/

class Solution
{
public:
  int kthFactor(int n, int k)
  {
    for (int i = 1; i <= n; ++i)
      if (n % i == 0 && --k == 0)
        return i;
    return -1;
  }
};