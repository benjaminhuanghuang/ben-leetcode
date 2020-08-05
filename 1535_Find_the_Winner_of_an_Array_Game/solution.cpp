/*
1535. Find the Winner of an Array Game

Level: Medium

https://leetcode.com/problems/find-the-winner-of-an-array-game
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
  https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1535-find-the-winner-of-an-array-game/
*/

class Solution
{
public:
  int getWinner(vector<int> &arr, int k)
  {
    int winner = arr[0];
    int win = 0;
    for (int i = 1; i < arr.size(); ++i)
    {
      if (arr[i] > winner)
      {
        winner = arr[i];
        win = 0;
      }
      if (++win == k)
        break;
    }
    return winner;
  }
};