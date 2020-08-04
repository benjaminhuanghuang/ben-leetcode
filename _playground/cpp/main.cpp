#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <numeric>
using namespace std;

vector<int> parse(string_view s)
  {
    int a{0}, b{0};
    int sign = 1;
    long t = 0;
    bool d = false;
    for (char c : s)
    {
      if (isdigit(c))
      {
        d = true;
        t = t * 10 + c - '0';
      }
      else
      {
        if (c == 'x')
          a += (d ? t : 1) * sign;
        else
        {
          b += t * sign;
          sign = c == '+' ? 1 : -1;
        }
        d = false;
        t = 0;
      }
    }
    b += t * sign;
    return {a, b};
  }

int main()
{
  vector<int> input = {1, 5, 9, 1, 5, 9};
  auto l = parse(string_view("1+2+3x+5"));
  cout << l[0] << " "<<l[1] << endl;
  return 0;
}