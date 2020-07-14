/*
1306. Jump Game III

Level: Medium

https://leetcode.com/problems/jump-game-iii
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
  Solution: BFS / DFS

  Time complexity: O(n)
  Space complexity: O(n)
*/

class Solution
{
public:
  bool canReach(vector<int> &arr, int start)
  {
    const int n = arr.size();
    vector<int> visted(n);
    visted[start] = 1;
    queue<int> q;
    q.push(start);
    while (q.size())
    {
      int cur = q.front();
      q.pop();
      if (arr[cur] == 0)
        return true;
      for (int i : {-1, 1})
      {
        int t = cur + i * arr[cur];
        if (t < 0 || t >= n || visted[t])
          continue;
        q.push(t);
        visted[t] = 1;
      }
    }
    return false;
  }
};