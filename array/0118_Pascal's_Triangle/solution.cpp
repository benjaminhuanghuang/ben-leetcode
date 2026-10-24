/*
118. Pascal's Triangle

https://leetcode.com/problems/pascals-triangle/
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
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for(int row =0; row < numRows; row++){
          vector<int> nums;
          for(int col =0; col <= row; col++){
              if(col == 0 || col == row)
              {
                nums.push_back(1);
              }
              else
              {
                 nums.push_back(res[row-1][col-1]+res[row-1][col]);
              }
          }
          res.push_back(nums);
        }
        return res;
    }
};