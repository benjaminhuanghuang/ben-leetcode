/*
944. Delete Columns to Make Sorted

Level: Easy

https://leetcode.com/problems/delete-columns-to-make-sorted
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
  https://zxi.mytechroad.com/blog/simulation/leetcode-944-delete-columns-to-make-sorted/
  Check descending case column by column.

  Time complexity: O(NL)

  Space complexity: O(1)
*/

class Solution
{
public:
  int minDeletionSize(vector<string> &A)
  {
    int ans = 0;
    for (int c = 0; c < A[0].size(); ++c)   // each char
      for (int r = 1; r < A.size(); ++r)    // each string
      {
        if (A[r][c] < A[r - 1][c])
        {
          ++ans;
          break;
        }
      }
    return ans;
  }
};