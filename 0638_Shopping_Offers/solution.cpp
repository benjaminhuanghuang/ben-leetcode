/*
638. Shopping Offers

Level: Medium

https://leetcode.com/problems/shopping-offers
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
  Try all combinations.
*/

class Solution
{
public:
  int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
  {
    int with_offer = INT_MAX;
    for (const auto &offer : special)
    {
      vector<int> new_needs(needs);
      bool valid_offer = true;
      for (int i = 0; i < price.size(); ++i)
        if (!(valid_offer &= ((new_needs[i] -= offer[i]) >= 0)))
          break;
      if (!valid_offer)
        continue;
      with_offer = min(with_offer, shoppingOffers(price, special, new_needs) + offer.back());
    }
    int without_offer = inner_product(begin(price), end(price), begin(needs), 0);
    return min(with_offer, without_offer);
  }
};