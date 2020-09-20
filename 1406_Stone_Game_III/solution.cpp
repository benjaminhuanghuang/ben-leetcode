/*
1406. Stone Game III

Level: Hard

https://leetcode.com/problems/stone-game-iii
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
#include <functional>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  https://zxi.mytechroad.com/blog/game-theory/leetcode-1406-stone-game-iii/
  Solution: DP

*/

class Solution {
public:
  string stoneGameIII(vector<int>& stoneValue) {
    const int n = stoneValue.size();
    vector<int> mem(n, INT_MIN);
    
    // Maximum `relative score` the current player can achieve
    // if start from the i-th stone.
    function<int(int)> dp = [&](int i) {
      if (i >= n) return 0; // end of game.
      if (mem[i] != INT_MIN) return mem[i];      
      for (int j = 0, s = 0; j < 3 && i + j < n; ++j) {
        s += stoneValue[i + j];
        // s - dp(.) to get `relative score`.
        mem[i] = max(mem[i], s - dp(i + j + 1));
      }      
      return mem[i];
    };
    
    const int score = dp(0);    
    return score > 0 ? "Alice" : (score == 0 ? "Tie" : "Bob");
  }
};

