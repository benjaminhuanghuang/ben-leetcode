/*
509. Fibonacci Number

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.

https://leetcode.com/problems/fibonacci-number/
*/

class Solution
{
public:
  int fib(int N)
  {
    if (N < 2)
      return N;

    int a = 0;
    int b = 1;
    for (int i = 2; i <= N; i++)
    {
      int f = a + b;
      a = b;
      b = f;
    }
    return b;
  }
};