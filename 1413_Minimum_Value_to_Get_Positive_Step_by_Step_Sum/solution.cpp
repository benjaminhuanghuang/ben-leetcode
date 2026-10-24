#include <vector>
#include <string>
#include <climits>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution:

*/

class Solution
{
public:
  int minStartValue(vector<int> &nums)
  {
    int size = nums.size();
    int miniStartVal = 0;
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
      sum += nums[i];
      miniStartVal = min(miniStartVal, sum);
    }

    if (miniStartVal < 0)
      return -miniStartVal + 1;
    else
      return 1;
  }
};