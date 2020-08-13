/*
1333. Filter Restaurants by Vegan-Friendly, Price and Distance

Level: Medium

https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance
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
  vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
  {
    vector<pair<int, int>> rs; // <rating, id>

    for (auto &r : restaurants)
      if ((!veganFriendly || veganFriendly && r[2]) && r[3] <= maxPrice && r[4] <= maxDistance)
        rs.emplace_back(r[1], r[0]);

    sort(rbegin(rs), rend(rs));
    
    vector<int> ans;
    for (const auto &r : rs)
      ans.push_back(r.second);
    return ans;
  }
};