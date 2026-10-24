/*
171. Excel Sheet Column Number

Level: Easy

https://leetcode.com/problems/excel-sheet-column-number


- 168. Excel Sheet Column Title
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

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
  int titleToNumber(string s)
  {
    int n = 0;
    int length = s.size();
    for (int i = length - 1; i >= 0; i--)
    {
      n += (s[i] - 'A' + 1) * pow(26, length - 1 - i);
    }
    return n;
  }
};