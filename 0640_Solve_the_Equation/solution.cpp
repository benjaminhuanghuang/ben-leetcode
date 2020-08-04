/*
640. Solve the Equation

Level: Medium

https://leetcode.com/problems/solve-the-equation
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  string solveEquation(string equation)
  {
    auto pos = equation.find('=');
    // get l[0] * x + l[1] = r[0] * x + r[1];
    auto l = parse(string_view(equation).substr(0, pos));
    auto r = parse(string_view(equation).substr(pos + 1));
    l[0] -= r[0];
    l[1] -= r[1];
    if (l[0] == 0)
      return l[1] == 0 ? "Infinite solutions" : "No solution";
    return "x=" + to_string(-l[1] / l[0]);
  }

private:
  vector<int> parse(string_view s)
  {
    //
    int coefficient{0}, num{0};
    int sign = 1;
    long temp = 0;
    bool parsingDigit = false;
    for (char c : s)
    {
      if (isdigit(c))
      {
        parsingDigit = true;
        temp = temp * 10 + c - '0';
      }
      else
      { 
        if (c == 'x')
          coefficient += (parsingDigit ? temp : 1) * sign;
        else
        { // +, -
          num += temp * sign;
          sign = c == '+' ? 1 : -1;
        }
        parsingDigit = false;
        temp = 0;
      }
    }
    num += temp * sign;
    return {coefficient, num};
  }
};