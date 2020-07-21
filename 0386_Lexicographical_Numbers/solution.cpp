/*
386. Lexicographical Numbers

Level: Medium

https://leetcode.com/problems/lexicographical-numbers
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

1、如果一个数乘以十以后没有超过n，那它后面紧挨着的应该是它的十倍，比如1,10,100。

2、如果不满足1，那就应该是直接加一，比如n为13的时候，前一个数为12，120超过了n，那接着的应该是13。
但是这里要注意如果前一个数的个位已经是9或者是它就是n了，那就不能加一了，比如 n = 25，前一个数为19，
下一个数应该为2而不是19+1=20。25的下一个也没有26了。

3、如果不满足2，比如19后面应该接2而不是20，这时候应该将19除以10再加一，比如n=500，399的下一个应该是4，那就是除以十，
个位还是9，继续除以10，得到3，加一得到4。
*/

class Solution
{
public:
  vector<int> lexicalOrder(int n)
  {
    vector<int> res;
    int cur = 1;
    for (int i = 1; i <= n; i++)
    {
      res.push_back(cur);
      if (cur * 10 <= n)
      {
        cur *= 10;
      }
      else
      {
        if (cur >= n)
          cur /= 10;
        cur += 1;
        while (cur % 10 == 0)
          cur /= 10;
      }
    }
    return res;
  }
};