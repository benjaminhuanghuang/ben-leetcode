/*
978. Longest Turbulent Subarray

https://leetcode.com/problems/longest-turbulent-subarray/
*/
#include <vector>
#include <stack>

using namespace std;

/*
如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是Turbulent
*/
class Solution
{
public:
  int maxTurbulenceSize(vector<int> &A)
  {
    vector<int> up(A.size(), 1);
    vector<int> down(A.size(), 1);
    int ans = 1;
    for (int i = 1; i < A.size(); ++i)
    {
      if (A[i] > A[i - 1])
        up[i] = down[i - 1] + 1;
      if (A[i] < A[i - 1])
        down[i] = up[i - 1] + 1;
      ans = max(ans, max(up[i], down[i]));
    }
    return ans;
  }
};