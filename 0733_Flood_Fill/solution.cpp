/*
733. Flood Fill

Level: Easy

https://leetcode.com/problems/flood-fill
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
private:
  void dfs(vector<vector<int>> &image, int r, int c, int color, int newColor)
  {
    if (image[r][c] == color)
    {
      image[r][c] = newColor;
      if (r >= 1)
        dfs(image, r - 1, c, color, newColor);
      if (c >= 1)
        dfs(image, r, c - 1, color, newColor);
      if (r + 1 < image.size())
        dfs(image, r + 1, c, color, newColor);
      if (c + 1 < image[0].size())
        dfs(image, r, c + 1, color, newColor);
    }
  }

public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
  {
    int color = image[sr][sc];
    if (color != newColor)
      dfs(image, sr, sc, color, newColor);
    return image;
  }

  vector<vector<int>> floodFill_v2(vector<vector<int>> &image, int sr, int sc, int newColor)
  {
    int color = image[sr][sc];

    const int columnMax = image[sr].size();
    const int rowMax = image.size();

    std::stack<std::pair<int, int>> coords;
    if (color != newColor)
    {
      coords.push({sr, sc});
    }

    while (!coords.empty())
    {
      auto [row, column] = coords.top();
      coords.pop();

      if (image[row][column] == color)
      {
        image[row][column] = newColor;

        if (row >= 1)
        {
          coords.push({row - 1, column});
        }

        if (row + 1 < rowMax)
        {
          coords.push({row + 1, column});
        }

        if (column >= 1)
        {
          coords.push({row, column - 1});
        }

        if (column + 1 < columnMax)
        {
          coords.push({row, column + 1});
        }
      }
    }

    return image;
  }
};