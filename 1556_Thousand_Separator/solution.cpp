/*
1556. Thousand Separator

Level: Easy

https://leetcode.com/problems/thousand-separator
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
  string thousandSeparator(int n)
  {
    string ans;
    int len = 0;
    while (true)
    {
      int digit = n % 10;

      ans = to_string(digit) + ans;
      len++;
      n = n / 10;
      if (n == 0)
      {
        break;
      }
      else
      {
        if (len % 3 == 0)
        {
          ans = '.' + ans;
        }
      }
    }
    return ans;
  }
};

class Solution
{
public:
  string thousandSeparator(int n)
  {
    string ans;
    int count = 0;
    do
    {
      if (count++ % 3 == 0 && ans.size())
        ans = "." + ans;
      ans = to_string(n % 10) + ans;
      n /= 10;
    } while (n);
    return ans;
  }
};