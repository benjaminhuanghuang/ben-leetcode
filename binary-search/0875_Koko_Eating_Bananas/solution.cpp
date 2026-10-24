/*
875. Koko Eating Bananas

Level: Medium

https://leetcode.com/problems/koko-eating-bananas
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
https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-875-koko-eating-bananas/

search for the smallest k [1, max_pile_height] such that eating time h <= H.
当求出了 mid 之后，需要统计用该速度吃完所有的香蕉堆所需要的时间，
统计的方法就是遍历每堆的香蕉个数，然后算吃完该堆要的时间。比如 K=4，那么假如有3个香蕉，需要1个小时，有4香蕉，还是1个小时，有5个香蕉，就需要两个小时，
如果将三种情况融合为一个式子呢，就是用吃速加上香蕉个数减去1，再除以吃速即可，即 (pile-1)/mid + 1 = (pile+mid-1)/mid，
*/

class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int H) {
    int l = 1;
    int r = *max_element(begin(piles), end(piles)) + 1;
    while (l < r) {
      int m = (r - l) / 2 + l;
      int h = 0;
      // total time
      for (int p : piles)
        h += (p + m - 1) / m;
      if (h <= H)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};

/*
  Solution: 
  https://www.cnblogs.com/grandyang/p/10807121.html
*/

class Solution
{
public:
  int minEatingSpeed(vector<int> &piles, int H)
  {
    int left = 1, right = 1e9;
    while (left < right)
    {
      int mid = left + (right - left) / 2, cnt = 0;
      for (int pile : piles)
        cnt += (pile + mid - 1) / mid;
      if (cnt > H)
        left = mid + 1;
      else
        right = mid;
    }
    return right;
  }
};
