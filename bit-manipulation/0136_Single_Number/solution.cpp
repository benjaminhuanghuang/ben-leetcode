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
  int singleNumber(vector<int> &nums)
  {
    int ans = 0;
    for (int n : nums)
    {
      ans ^= n;
    }
    return ans;
  }
};