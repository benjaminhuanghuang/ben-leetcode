/*
874. Walking Robot Simulation

Level: Easy

https://leetcode.com/problems/walking-robot-simulation
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
  /*
    Time complexity: O(n + sum(x)) = O(n)
    Space complexity: O(n)
  */
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
  {
    // north, west, south, east
    vector<vector<int>> dirs{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    // face north
    int currDir = 0;
    int x = 0;
    int y= 0;

    unordered_map<int, unordered_set<int>> map;
    for (const auto obstacle : obstacles)
      map[obstacle[0]].insert(obstacle[1]);

    int ans = 0;
    for (int c : commands) {      
      if (c == -2)    // turn left 90
        currDir = (currDir + 1 ) % 4;
      else if (c == -1)  // turn right 90
        currDir = (currDir - 1 + 4) % 4;
      else {
        while (c--) {
          int tx = x + dirs[currDir][0];
          int ty = y + dirs[currDir][1];
          if (map.count(tx) && map.at(tx).count(ty))
            break;
          x = tx;
          y = ty;
          ans = max(ans, x * x + y * y);          
        }
      }
    }
    return ans;
  }
};