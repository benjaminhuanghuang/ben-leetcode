/*
240. Search a 2D Matrix II

Level: Medium

https://leetcode.com/problems/search-a-2d-matrix-ii
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
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    if (matrix.empty() || matrix[0].empty())
      return false;
    const int m = matrix.size();
    const int n = matrix[0].size();
    int r = 0;
    int c = matrix[0].size() - 1;
    while (r < m && c >= 0)
    {
      if (matrix[r][c] == target)
        return true;
      else if (matrix[r][c] > target)
        --c;
      else
        ++r;
    }
    return false;
  }
};