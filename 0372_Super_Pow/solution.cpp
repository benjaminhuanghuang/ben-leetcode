/*
372. Super Pow

Level: Medium

https://leetcode.com/problems/super-pow
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

  //c % m = (a * b) % m  = [(a % m) * (b % m)] % m

*/

class Solution
{
public:
  int superPow(int a, vector<int> &b)
  {
    int result = 1;

    for (int i = 0; i < b.size(); i++)
    {
      result = helper(result, 10) * helper(a, b[i]) % 1337; // result^10
    }

    return result;
  }
  int helper(int x, int n)
  {
    if (n == 0)
      return 1;
    if (n == 1)
      return x % 1337;

    return helper(x % 1337, n / 2) * helper(x % 1337, n - n / 2) % 1337;
  }
};