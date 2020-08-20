/*
327. Count of Range Sum

Level: Hard

https://leetcode.com/problems/count-of-range-sum
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: segment tree 
  给了一个数组，又给了一个下限和一个上限，求有多少个不同的区间使得每个区间的和在给定的上下限之间。

*/

class Solution
{
public:
  int countRangeSum(vector<int> &nums, int lower, int upper)
  {
    set<long long> s;
    long long sum = 0, n = 0, ret = 0, lo, up;
    for (int &x : nums)
    {
      s.insert(-sum);
      sum += x;
    }
    unordered_map<int, int> m;
    for (auto it = s.begin(); it != s.end(); it++)
      m[*it] = n++;
    vector<int> segtree(2 * n);
    sum = 0;
    for (int &x : nums)
    {
      update(m[-sum], segtree, n);
      sum += x;
      auto it1 = s.lower_bound(lower - sum);
      if (it1 == s.end())
        continue;
      auto it2 = s.upper_bound(upper - sum);
      if (it2 == s.begin())
        continue;
      it2--;
      ret += query(segtree, m[*it1], m[*it2], n);
    }
    return ret;
  }
  void update(int a, vector<int> &segtree, int n)
  {
    for (a += n; a; a >>= 1)
      segtree[a]++;
  }
  int query(vector<int> &segtree, int a, int b, int n)
  {
    int ret = 0;
    for (a += n, b += n; a <= b; a >>= 1, b >>= 1)
    {
      if (a & 1)
        ret += segtree[a++];
      if (!(b & 1))
        ret += segtree[b--];
    }
    return ret;
  }
};