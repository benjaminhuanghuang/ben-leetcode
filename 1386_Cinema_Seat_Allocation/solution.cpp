/*
1386. Cinema Seat Allocation

Level: Medium

https://leetcode.com/problems/cinema-seat-allocation
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
  https://zxi.mytechroad.com/blog/hashtable/leetcode-1386-cinema-seat-allocation/
*/

class Solution
{
public:
  int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
  {
    unordered_map<int, int> rows;
    for (auto &seat : reservedSeats)
      rows[seat[0]] |= 1 << (seat[1] - 1);

    int ans = (n - rows.size()) * 2;

    for (const auto &[idx, row] : rows)
    {
      int s2 = row & 0b0000011110;
      int s4 = row & 0b0001111000;
      int s6 = row & 0b0111100000;
      if (s2 == 0 && s6 == 0)
        ans += 2;
      else if (s2 == 0 || s4 == 0 || s6 == 0)
        ans += 1;
    }

    return ans;
  }
};