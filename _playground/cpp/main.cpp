#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <numeric>
using namespace std;

//-----------------------------------------

int divide(int dividend, int divisor)
  {
    if (divisor == 0)
      return INT_MAX;
    bool isPositive = !((dividend > 0) ^ (divisor > 0));

    long dividendL = abs((long)dividend);   // abs(-2147483648) overflow
    long divisorL = abs((long)divisor);

    long result = 0;           // result can be 2147483648
    // 
    while (dividendL >= divisorL)
    {
      long cur = 1;
      long start = divisorL;
      //用除数每次*2（向左移动一位）去逼近被除数，被除数减去新的除数如此循环。
      while ((start << 1) <= dividendL)
      {
        start <<= 1;
        cur <<= 1;
      }
      dividendL -= start;
      result += cur;
    }

    return isPositive ? min(INT_MAX, (int)result) : max(INT_MIN, (int)-result);
  }

int main()
{
  //vector<int> input = {2, 0, 6, 6};
  auto ans = divide(-2147483648 , -1);
  cout << ans << endl;
}
