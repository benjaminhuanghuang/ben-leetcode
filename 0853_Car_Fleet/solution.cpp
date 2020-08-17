/*
853. Car Fleet

Level: Medium

https://leetcode.com/problems/car-fleet
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
  https://zxi.mytechroad.com/blog/greedy/leetcode-853-car-fleet/
*/

class Solution
{
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed)
  {
    vector<pair<int, float>> cars(position.size());
    for (int i = 0; i < position.size(); ++i)
      cars[i] = {position[i], static_cast<float>(target - position[i]) / speed[i]};
    sort(rbegin(cars), rend(cars));
    int ans{0};
    float max_t{0};
    for (const auto &[p, t] : cars)
      if (t > max_t)
      {
        max_t = t;
        ++ans;
      }
    return ans;
  }
};