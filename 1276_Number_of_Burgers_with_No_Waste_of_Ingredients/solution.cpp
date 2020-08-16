/*
1276. Number of Burgers with No Waste of Ingredients

Level: Medium

https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients
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
  Solution: 鸡兔同笼
  https://www.cnblogs.com/wentiliangkaihua/p/11980598.html
*/

class Solution
{
public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
  {
    // Jumbo = x, small = y
    // 4x + 2y = T
    // x + y = C
    // x = (T - 2C) / 2
    int x = tomatoSlices / 2 - cheeseSlices;
    int y = cheeseSlices - x;
    if (4 * x + 2 * y == tomatoSlices && x >= 0 && y >= 0)
      return {x, y};
    return {};
  }
};