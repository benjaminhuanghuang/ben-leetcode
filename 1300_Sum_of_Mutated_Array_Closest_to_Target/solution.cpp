/*
1300. Sum of Mutated Array Closest to Target

Level: Medium

https://leetcode.com/problems/sum-of-mutated-array-closest-to-target
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
  https://www.acwing.com/file_system/file/content/whole/index/content/285233/

  求出一个最小的 value，满足大于等于 target，然后我们比较 value - 1 和 value 哪个更接近 target。
  求满足大于等于 target 的最小值，显然可以采用二分答案然后判定的方式。如果当前二分的 value 计算出来的结果小于 target，则继续向上二分。否则，向下二分。
  二分的下界为 0，上界为数组的最大值。
*/

class Solution
{
public:
  int calc(int v, const vector<int> &arr)
  {
    int s = 0;
    for (int x : arr)
      s += min(v, x);
    return s;
  }

  int findBestValue(vector<int> &arr, int target)
  {
    int n = arr.size();
    int l = 0, r = arr[0];

    for (int i = 1; i < n; i++)
      r = max(r, arr[i]);

    while (l < r)
    {
      int mid = (l + r) >> 1;
      if (calc(mid, arr) < target)
        l = mid + 1;
      else
        r = mid;
    }
    if (abs(calc(l - 1, arr) - target) <= abs(calc(l, arr) - target))
      return l - 1;
    return l;
  }
};