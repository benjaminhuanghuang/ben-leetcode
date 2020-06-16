/*
1431. Kids With the Greatest Number of Candies

Level: Easy

https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
*/
#include <vector>
#include <string>
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
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
  {
    int maxCandy = *max_element(candies.begin(), candies.end());
    vector<bool> res;

    for (auto candy : candies)
    {
      res.push_back(candy + extraCandies >= maxCandy);
    }
    return res;
  }
};