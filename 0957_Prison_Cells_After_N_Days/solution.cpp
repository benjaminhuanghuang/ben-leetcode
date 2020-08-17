/*
957. Prison Cells After N Days

Level: Medium

https://leetcode.com/problems/prison-cells-after-n-days
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
*/

class Solution
{
public:
  vector<int> prisonAfterNDays(vector<int> &cells, int N)
  {
    vector<int> seen(1 << 8, -1);
    auto getKey = [](const vector<int> &cells) {
      int key = 0;
      for (int i = 0; i < 8; ++i)
        key |= cells[i] << i;
      return key;
    };
    while (N > 0)
    {
      const int key = getKey(cells);
      if (seen[key] > 0)
        N %= seen[key] - N;
      seen[key] = N--;
      if (N < 0)
        break;
      vector<int> c(8);
      for (int i = 1; i < 7; ++i)
        c[i] = cells[i - 1] == cells[i + 1];
      cells.swap(c);
    }
    return cells;
  }
};