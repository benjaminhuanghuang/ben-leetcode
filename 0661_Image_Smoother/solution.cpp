/*
661. Image Smoother
https://leetcode.com/problems/image-smoother/

将每一个像素的值换成其周围9个单元格的平均值。
*/
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &M)
  {
    if (M.empty() || M[0].empty())
      return {};
    int rows = M.size(), cols = M[0].size();
    vector<vector<int>> res(rows, vector<int>(cols, 0));
    vector<vector<int>> dirs{{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        int cnt = M[i][j], all = 1;
        for (auto dir : dirs)
        {
          int x = i + dir[0], y = j + dir[1];
          if (x < 0 || x >= rows || y < 0 || y >= cols)
            continue;
          ++all;
          cnt += M[x][y];
        }
        res[i][j] = cnt / all;
      }
    }
    return res;
  }
};