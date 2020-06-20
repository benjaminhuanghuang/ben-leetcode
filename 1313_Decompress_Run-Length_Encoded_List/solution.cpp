/*
1313. Decompress Run-Length Encoded List

Level: Easy

https://leetcode.com/problems/decompress-run-length-encoded-list/

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
  vector<int> decompressRLElist(vector<int> &nums)
  {
    vector<int> ans;

    for (int i = 0; i < nums.size(); i = i + 2)
    {
      for (int n = 0; n < nums[i]; n++)
      {
        ans.push_back(nums[i + 1]);
      }
    }
    return ans;
  }
};