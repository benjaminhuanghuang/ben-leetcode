/*
50. Pow(x, n)

Level: Medium

https://leetcode.com/problems/powx-n
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
  double myPow(double x, int n)
  {
    return n >= 0 ? myPowImp(x, n) : 1.0 / myPowImp(x, n);
  }

private:
  // x^n = x^(n/2)*x^(n/2)*x^(n%2)
  double myPowImp(double x, int n)
  {
    if (n == 0)
      return 1;
    return myPowImp(x * x, n / 2) * (n % 2 ? x : 1);
  }
};