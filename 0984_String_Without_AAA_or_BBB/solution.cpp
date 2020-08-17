/*
984. String Without AAA or BBB

Level: Medium

https://leetcode.com/problems/string-without-aaa-or-bbb
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
  https://zxi.mytechroad.com/blog/greedy/leetcode-984-string-without-aaa-or-bbb/
*/

class Solution
{
public:
  string strWithout3a3b(int A, int B)
  {
    char a = 'a';
    char b = 'b';
    if (B > A)
    {
      swap(A, B);
      swap(a, b);
    }
    string ans;
    while (A || B)
    {
      if (A > 0)
      {
        ans += a;
        --A;
      }
      if (A > B)
      {
        ans += a;
        --A;
      }
      if (B > 0)
      {
        ans += b;
        --B;
      }
    }
    return ans;
  }
};