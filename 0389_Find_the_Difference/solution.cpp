/*
389. Find the Difference

Level: Easy

https://leetcode.com/problems/find-the-difference
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
  char findTheDifference(string s, string t)
  {
    char ans = (char)0;
    for (int i = 0; i < s.size(); i++)
    {
      ans ^= s[i];
    }
    for (int i = 0; i < t.size(); i++)
    {
      ans ^= t[i];
    }
    return ans;
  }
};