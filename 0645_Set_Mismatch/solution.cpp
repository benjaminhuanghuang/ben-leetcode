/*
645. Set Mismatch

Level: Easy

https://leetcode.com/problems/set-mismatch
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
  vector<int> findErrorNums(vector<int> &nums)
  {
    vector<int> res(2);

    bool map[nums.size() + 1];
    fill(map, map + nums.size() + 1, false);

    for (int num : nums)
      if (map[num] == false)
        map[num] = true;
      else
        res[0] = num; // occurs twice

    for (int i = 1; i < (nums.size() + 1); i++)
      if (map[i] == false)
      {
        res[1] = i; // missed
        break;
      }
    return res;
  }
};