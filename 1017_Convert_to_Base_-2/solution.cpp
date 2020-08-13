/*
1017. Convert to Base -2 [Medium]

https://leetcode.com/problems/convert-to-base-2/
*/

#include <string>
#include <vector>

using namespace std;

/*
  https://zxi.mytechroad.com/blog/uncategorized/leetcode-weekly-contest-130/
  3 / -2 = -1 ... 1
  -3 / -2 = 1 ... -1

*/
class Solution
{
public:
  string baseNeg2_huahua(int N)
  {
    if (N == 0)
      return "0";
    return baseNegK(N, -2);
  }

  string baseNeg2_huahua2(int N)
  {
    if (N == 0)
      return "0";
    vector<char> ans;
    while (N)
    {
      ans.push_back((N & 1) + '0');
      N = -(N >> 1); // 负数右移会减1
    }
    return {rbegin(ans), rend(ans)};
  }

  // https://www.youtube.com/watch?v=AaMhFrzgt8M
  string baseNeg2_xingxing(int N)
  {
    string res;
    while (N)
    {
      res = (N % -2 ? "1" : "0") + res;
      N = -(N >> 1);
    }
    return res.size() ? res : "0";
  }

private:
  string baseNegK(int N, int K)   // K = -2
  {
    vector<char> ans;
    while (N)
    {
      int r = N % K;
      N /= K;
      if (r < 0)   //余数最终会成为结果中的每一位 要么为0 要么为正数
      {
        r += -K;
        N += 1;
      }
      ans.push_back(r + '0');
    }
    return {rbegin(ans), rend(ans)};
  }
};