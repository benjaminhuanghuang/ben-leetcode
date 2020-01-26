/*
566. Reshape the Matrix

https://leetcode.com/problems/reshape-the-matrix/
*/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int rows = nums.size();
        int cols = nums[0].size();
        if (rows * cols != r * c)
            return nums;

        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < rows * cols; i++)
        {
            ans[i / c][i % c] = nums[i / cols][i % cols];
        }

        return ans;
    }
};