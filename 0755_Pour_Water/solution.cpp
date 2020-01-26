/*
  755.Pour Water [Medium, Locked]
*/

#include <vector>
using namespace std;

/*
https://zxi.mytechroad.com/blog/simulation/leetcode-755-pour-water/


给你地形的高度，有V单位的水会从K位置落下，问你稳定之后水位的高度。
*/

class Solution
{
public:
  vector<int> pourWater(vector<int> &heights, int V, int K)
  {
    while (V--)
      drop(heights, K);
    return heights;
  }

private:
  void drop(vector<int> &heights, int K)
  {
    int best = K;
    for (int d = -1; d <= 1; d += 2)
    {
      int i = K + d;
      while (i >= 0 && i < heights.size() && heights[i] <= heights[i - d])
      {
        if (heights[i] < heights[best])
          best = i;
        i += d;
      }
      if (best != K)
        break;
    }
    ++heights[best];
  }
};