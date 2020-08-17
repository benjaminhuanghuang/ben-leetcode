/*
1390. Four Divisors

Level: Medium

https://leetcode.com/problems/four-divisors
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
  https://www.youtube.com/watch?v=gv5bjFUJQqE
*/

class Solution
{
public:
  int sumFourDivisors(vector<int> &nums)
  {
    int ans = 0;
    for (int n : nums)
    {
      int r = sqrt(n);
      if (n <= 4 || r * r == n)
        continue;
      int count = 2;
      int sum = 1 + n;
      for (int d = 2; d <= r; ++d)
        if (n % d == 0)
        {
          count += 2;
          sum += n / d + d;
        }
      if (count == 4)
        ans += sum;
    }
    return ans;
  }
};