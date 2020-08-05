/*
1476. Subrectangle Queries

Level: Medium

https://leetcode.com/problems/subrectangle-queries
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
*/

class SubrectangleQueries
{
public:
  SubrectangleQueries(vector<vector<int>> &rectangle) : m_(rectangle)
  {
  }

  void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
  {
    for (int i = row1; i <= row2; ++i)
      for (int j = col1; j <= col2; ++j)
        m_[i][j] = newValue;
  }

  int getValue(int row, int col)
  {
    return m_[row][col];
  }

private:
  vector<vector<int>> m_;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */