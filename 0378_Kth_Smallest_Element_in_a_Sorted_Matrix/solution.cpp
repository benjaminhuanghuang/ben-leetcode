/*
378. Kth Smallest Element in a Sorted Matrix

Level: Medium

https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

# 240. Search a 2D Matrix II
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
  Solution:  Binary Search

  Find the smallest x, such that there are k elements that are smaller or equal to x.

  Time complexity: O(nlogn*log(max – min))

  Space complexity: O(1)
*/

class Solution
{
public:
  int kthSmallest(vector<vector<int>> &matrix, int k)
  {
    const int n = matrix.size();
    long l = matrix[0][0];
    long r = matrix[n - 1][n - 1] + 1;
    while (l < r)
    {
      long m = l + (r - l) / 2;
      int total = 0;
      int s = n;
      for (const auto &row : matrix)
        total += (s = distance(begin(row), upper_bound(begin(row), begin(row) + s, m)));

      if (total >= k)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};

class Solution
{
public:
  int kthSmallest(vector<vector<int>> &matrix, int k)
  {
    const int n = matrix.size();
    long l = matrix[0][0];
    long r = matrix[n - 1][n - 1] + 1;
    while (l < r)
    {
      // 注意优先级
      int mid = l + ((r - l) >> 1);
      int count = counter(matrix, mid);
      if (count < k)
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }

  /*
   is similar to 240. Search a 2D Matrix II. 
   The start point of such a sorted matrix is left-bottom corner.
  */
  int counter(vector<vector<int>> &matrix, int target)
  {
    int size = matrix.size();
    int row = size - 1;
    int col = 0;
    int count = 0;

    while (row >= 0 && col < size)
    {
      if (matrix[row][col] <= target)
      {
        count += row+1;  // add count in vertical
        col++;
      }
      else
      {
        row--;
      }
    }

    return count;
  }
};