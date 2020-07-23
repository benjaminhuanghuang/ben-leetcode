/*
473. Matchsticks to Square

Level: Medium

https://leetcode.com/problems/matchsticks-to-square
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
  https://www.youtube.com/watch?v=Z8cz4Wb5P2g
*/

class Solution
{
public:
  bool makesquare(vector<int> &nums)
  {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 4 != 0 || sum == 0)
      return false;

    sort(nums.begin(), nums.end(), greater<int>());
    vector<bool> visited(nums.size(), false);
    return dfs(nums, 0, sum/4, 0, 1, visited);
  }  

private:
  bool dfs(vector<int> &nums, int pos, int target, int currSum, int groupId, vector<bool>& visited)
  {
    if(groupId == 4) return true;
    if(currSum == target) return dfs(nums, 0, target, 0, groupId + 1, visited); 
    if(currSum > target) return false;

    for(int i = pos; i< nums.size(); i++){
      if(visited[i]) continue;
      if(i >0 &&  nums[i] == nums[i-1] && !visited[i-1]) continue;
      visited[i] = true;
      if(dfs(nums, i + 1, target, currSum+nums[i], groupId, visited))
        return true;
      visited[i] = false;    
    }
    return false;
  }
};