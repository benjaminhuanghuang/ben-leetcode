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