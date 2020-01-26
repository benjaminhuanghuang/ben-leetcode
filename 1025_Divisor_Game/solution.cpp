// https://leetcode.com/problems/divisor-game/

#include <vector>
using namespace std;
/*
  min-max search
  记忆化递归
*/
class Solution
{
public:
  bool divisorGame(int N)
  {
    _cache = vector<int>(N + 1, -1);
    return canWin(N);
  }

private:
  vector<int> _cache;
  bool canWin(int N)
  {
    if (N == 1)
      return false;
    if (_cache[N] != -1)
      return _cache[N];
    bool win = false;
    for (int i = 1; i < N; i++)
    {
      if (N % i == 0)
        win |= !canWin(N - i);
    }

    return _cache[N] = win;
  }
};