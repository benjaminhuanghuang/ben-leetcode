/*
119. Pascal's Triangle II

https://leetcode.com/problems/pascals-triangle-ii/
*/
#include <vector>
using namespace std;
/*
[
  [1],
  [1,1],
  [1,2,1],
  [1,3,3,1],
  [1,4,6,4,1]
]
*/
class Solution
{
public:
  vector<int> getRow(int rowIndex)
  {
    vector<int> res;
    for (int row = 0; row <= rowIndex; row++)
    {
      // Add 1 to the row
      res.insert(res.begin(), 1);
      // Calculate the values
      for (int col = 1; col < res.size() - 1; col++)
      {
        res[col] = res[col] + res[col + 1];
      }
    }
    return res;
  }
};