/*
1282. Group the People Given the Group Size They Belong To

Level: Medium

https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to
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
  Solution: HashMap + Greedy

    hashmap: group_size -> {ids}
    greedy: whenever a group of size s has s people, assign those s people to the same group.

    Time complexity: O(n)
    Space complexity: O(n)

*/

class Solution
{
public:
  vector<vector<int>> groupThePeople(vector<int> &groupSizes)
  {
    vector<vector<int>> ans;

    unordered_map<int, vector<int>> m;
    for (int i = 0; i < groupSizes.size(); ++i)
    {
      auto &group = m[groupSizes[i]];
      group.push_back(i);
      if (group.size() == groupSizes[i])
        ans.push_back(std::move(group));
    }
    return ans;
  }
};