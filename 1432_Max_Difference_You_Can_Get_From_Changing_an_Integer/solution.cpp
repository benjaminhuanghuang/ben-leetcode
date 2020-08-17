/*
1432. Max Difference You Can Get From Changing an Integer

Level: Medium

https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer
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
  把 num 中的各个数字依次替换成 0~9 ，从替换结果中找最大 - 最小。
*/
class Solution_BruteForce
{
public:
  int maxDiff(int num)
  {
    string str = to_string(num);
    int mn = INT_MAX, mx = INT_MIN;

    string s = "0123456789";
    int n = s.length();

    for (int i = 0; i < n; i++)  // 0 to 9
    {
      for (int j = 0; j < n; j++)
      {
        string rstr;
        // rstr = str.replace(str(i), str(j))
        for (int k = 0; k < str.length(); k++)
          rstr += (str[k] == s[i]) ? s[j] : str[k];
        if (rstr[0] == '0')
          continue;
        int val = stoi(rstr);
        mn = min(mn, val);
        mx = max(mx, val);
      }
    }

    return mx - mn;
  }
};

/*
  Solution: 
  最大值很好求，把第一个不是9的数字替换成9即可。
  最小值分两种情况，如果最高位不为1，那么替换成1；否则，找出第一个不为0的数字替换成0。
*/

class Solution
{
public:
  int maxDiff(int num)
  {
  }
};