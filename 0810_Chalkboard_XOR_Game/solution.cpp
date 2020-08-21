/*
810. Chalkboard XOR Game

Level: Hard

https://leetcode.com/problems/chalkboard-xor-game
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
  https://www.cnblogs.com/grandyang/p/9445951.html
*/

class Solution
{
public:
  bool xorGame(vector<int> &nums)
  {
    int x = 0, n = nums.size();
    for (int num : nums)
      x ^= num;
    return x == 0 || n % 2 == 0;
  }
};