/*
1433. Check If a String Can Break Another String

Level: Medium

https://leetcode.com/problems/check-if-a-string-can-break-another-string
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
  bool checkIfCanBreak(string s1, string s2)
  {
    int count1 = 0, count2 = 0;
    if (s1.length() != s2.length())
      return false;

    int l = s1.length();
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    for (int i = 0; i < l; i++)
    {
      if (s1[i] >= s2[i])
        count1++;
      if (s2[i] >= s1[i])
        count2++;
    }
    if (count1 == l || count2 == l)
      return true;
    return false;
  }
};