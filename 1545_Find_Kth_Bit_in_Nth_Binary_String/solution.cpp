/*
1545. Find Kth Bit in Nth Binary String

Level: Medium

https://leetcode.com/problems/find-kth-bit-in-nth-binary-string
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
  char findKthBit(int n, int k)
  {
    string ans = "0";
    for (int i = 2; i <= n && ans.length() < k; ++i)
    {
      string tmp(rbegin(ans), rend(ans));
      for (char &c : tmp)
        c = '1' - c + '0';
      ans = ans + "1" + tmp;
    }
    return ans[k - 1];
  }
};
/*
  Solution 2: Recursion

  All the strings have odd length of L = (1 << n) – 1,
  Let say the center m = (L + 1) / 2
  if n == 1, k should be 1 and ans is “0”.
  Otherwise
  if k == m, we know it’s “1”.
  if k < m, the answer is the same as find(n-1, K)
  if k > m, we are finding a flipped and mirror char in S(n-1), thus the answer is flip(find(n-1, L – k + 1)).

  Time complexity: O(n)
  Space complexity: O(n)
*/

class Solution {
public:
  char findKthBit(int n, int k) {
    if (n == 1) return '0';
    int l = (1 << n) - 1;
    if (k == (l + 1) / 2) return '1';
    else if (k < (l + 1) / 2) 
      return findKthBit(n - 1, k);
    else
      return '1' - findKthBit(n - 1, l - k + 1) + '0';
  }
};