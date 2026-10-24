#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> transpose(vector<vector<int>> &A)
  {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int>> ans(cols, vector<int>(rows));
    for (int r = 0; r < rows; ++r)
      for (int c = 0; c < cols; ++c)
        ans[c][r] = A[r][c];
    return ans;
  }
};
