/*
1374. Generate a String With Characters That Have Odd Counts

Level: Easy

https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts
*/
#include <vector>
#include <string>
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
  string generateTheString(int n)
  {
    string ans;
    if (n & 1) // odd
    {
      for (int i = 0; i < n; i++)
      {
        ans += 'a';
      }
    }
    else
    {
      for (int i = 0; i < n - 1; i++)
      {
        ans += 'a';
      }
      ans += 'b';
    }
    return ans;
  }

  string generateTheString_v2(int n)
  {
    string result;

    if (n & 1)
    {
      result.insert(result.begin(), n, 'a');
    }
    else
    {
      result.insert(result.begin(), 1, 'a');
      result.insert(result.end(), n - 1, 'b');
    }
    return result;
  }
};