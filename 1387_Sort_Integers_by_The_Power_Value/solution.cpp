/*
1387. Sort Integers by The Power Value

Level: Medium

https://leetcode.com/problems/sort-integers-by-the-power-value
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
  int getKth(int lo, int hi, int k)
  {
    vector<pair<int, int>> vals;

    for (int n = lo; n <= hi; ++n)
    {
      int p = 0;
      int x = n;
      while (x != 1)
      {
        if (x & 1)
          x = 3 * x + 1;
        else
          x /= 2;
        ++p;
      }
      vals.emplace_back(p, n);
    }
    /*
      nth_element仅排序第n个元素（从0开始索引），即将位置n（从0开始）的元素放在第n大的位置，
      处理完之后，默认排在它前面的元素都不比它大，排在它后面的元素都不比它小。
    */
    // nth_element(begin(vals), begin(vals) + k - 1, end(vals));

    sort(begin(vals), end(vals));
    return vals[k - 1].second;
  }
};