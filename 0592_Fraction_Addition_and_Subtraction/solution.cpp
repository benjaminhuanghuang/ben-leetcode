/*
592. Fraction Addition and Subtraction

Level: Medium

https://leetcode.com/problems/fraction-addition-and-subtraction
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
#include <sstream>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution:  a/b + c/d = (a * d + b * c) / b * d
*/

class Solution
{
public:
  string fractionAddition(string expression)
  {
    int a = 0;
    int b = 1;
    int c;
    int d;
    char slash;
    istringstream in(expression);
    while (in >> c >> slash >> d)
    {
      a = a * d + b * c;
      b *= d;
      int gcd = abs(__gcd(a, b));
      a /= gcd;
      b /= gcd;
    }
    return to_string(a) + "/" + to_string(b);
  }
};