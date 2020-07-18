/*
319. Bulb Switcher

Level: Medium

https://leetcode.com/problems/bulb-switcher
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
  // 一个灯泡只有被操作奇数次，最终才会亮。
  // 如果n可以分解为a*b，那么在第ａ轮和第ｂ也会被各操作一次。
  // 但是当n = k * k时，只会被操作一次，因此可以知道只有当ｎ可以被分解为一个数的平方的时候才会出现奇数次操作，最终才会保持亮。
 */

class Solution
{
public:
  int bulbSwitch(int n)
  {
    return (int)sqrt(n);
  }
};