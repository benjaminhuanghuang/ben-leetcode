/*
1007. Minimum Domino Rotations For Equal Row

https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

*/
#include <vector>
#include <string>
#include <unordered_set>
#include <climits>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  https://zxi.mytechroad.com/blog/algorithms/array/1007-minimum-domino-rotations-for-equal-row/

  Solution: 
*/

class Solution
{
public:
  int minDominoRotations(vector<int> &A, vector<int> &B)
  {
    int ans = INT_MAX;
    for (int r = 1; r <= 6; ++r)
    {
      bool flag = true;
      int count_a = 0;
      int count_b = 0;
      for (int i = 0; i < A.size(); ++i)
      {
        if (A[i] != r && B[i] != r)
        {
          flag = false;
          break;
        }
        else if (A[i] == r && B[i] == r)
          continue;
        else if (A[i] == r)
        {
          ++count_a;
        }
        else if (B[i] == r)
        {
          ++count_b;
        }
      }
      if (flag)
        ans = min(ans, min(count_a, count_b));
    }
    return ans == INT_MAX ? -1 : ans;
  }
};