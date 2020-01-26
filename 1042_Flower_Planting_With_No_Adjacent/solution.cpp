/*
1042. Flower Planting With No Adjacent

https://leetcode.com/problems/flower-planting-with-no-adjacent/
*/

#include <vector>

using namespace std;

/*
因为一个garden最多有3条path连接到别的garden，而且color一共有4种，所以我们只要从头到尾模拟着色就可以了
*/
class Solution
{
public:
  vector<int> gardenNoAdj(int N, vector<vector<int>> &paths)
  {
    vector<int> res(N, 0);
    vector<vector<int>> g(N);

    for (auto &p : paths)
    {
      g[p[0] - 1].push_back(p[1] - 1);
      g[p[1] - 1].push_back(p[0] - 1);
    }

    for (int i = 0; i < N; i++)
    {
      int used = 0;
      for (auto &n : g[i])
        used |= 1 << res[n];
      for (int c = 1; c <= 4; c++)
      {
        if ((used >> c & 1) == 0)
        {
          res[i] = c;
          break;
        }
      }
    }
    return res;
  }
};