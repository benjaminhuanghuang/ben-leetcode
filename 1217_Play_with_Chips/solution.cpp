/*
1217. Play with Chips

Level: Easy

https://leetcode.com/problems/play-with-chips
*/
#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  最终的位置只分为奇数和偶数两种情况。
  对于奇数的位置，所有偶数位置的筹码需要代价为 1；对于偶数位置，所有奇数位置的筹码需要代价为 1。
  所以最终答案就是奇数的个数或者偶数的个数。
*/

class Solution
{
public:
  int minCostToMoveChips(vector<int> &chips)
  {
    int count = chips.size();
    int odds = 0;
    for (int i = 0; i < count; i++)
      odds += chips[i] & 1;

    return min(odds, count - odds);
  }
};