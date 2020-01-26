/*
1006. Clumsy Factorial
https://leetcode.com/problems/clumsy-factorial/

*/


/*
https://zxi.mytechroad.com/blog/simulation/leetcode-1006-clumsy-factorial/
*/
class Solution
{
public:
  int clumsy(int N)
  {
    if (N <= 0)
      return 0;
    if (N == 1)
      return 1;
    if (N == 2)
      return 2 * 1;
    if (N == 3)
      return 3 * 2 / 1;

    int ans = N * (N - 1) / (N - 2) + (N - 3);

    while ((N -= 4) >= 4)
      ans = ans - N * (N - 1) / (N - 2) + (N - 3);

    return ans - clumsy(N);
  }
};