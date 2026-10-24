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
*/

class Solution
{
public:
  int numTimesAllBlue(vector<int> &light)
  {
    int ans = 0;
    int right = 0;
    for (int i = 0; i < light.size(); ++i)
    {
      right = max(right, light[i]);
      ans += right == i + 1;
    }
    return ans;
  }
};