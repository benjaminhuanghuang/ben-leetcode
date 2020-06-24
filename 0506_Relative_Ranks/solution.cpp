/*
506. Relative Ranks

Level: Easy

https://leetcode.com/problems/relative-ranks
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
  vector<string> findRelativeRanks(vector<int> &nums)
  {
    vector<pair<int, int>> ranks; // <score, index>
    for (int i = 0; i < nums.size(); i++)
    {
      ranks.push_back({nums[i], i});
    }
    // sory by score, big to small
    // cmp indicates whether the element passed as first argument is considered to go before the second 
    sort(ranks.begin(), ranks.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.first > b.first; });

    vector<string> result;

    for (int i = 0; i < nums.size(); i++)
    {
      if (i == 0)
      {
        result[ranks[i].second] = "Gold Medal";
      }
      else if (i == 1)
      {
        result[ranks[i].second] = "Silver Medal";
      }
      else if (i == 2)
      {
        result[ranks[i].second] = "Bronze Medal";
      }
      else
      {
        result[ranks[i].second] = to_string(i + 1);
      }
    }

    return result;
  }
};