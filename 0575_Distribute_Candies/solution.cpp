/*
575. Distribute Candies

Level: Easy

https://leetcode.com/problems/distribute-candies
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
  //首先求出糖果种类，每人可获得糖果数为candies.Length / 2
  int distributeCandies(vector<int> &candies)
  {
    unordered_set<int> candySet(candies.begin(), candies.end());
    return min(candySet.size(), candies.size() / 2);
  }
};