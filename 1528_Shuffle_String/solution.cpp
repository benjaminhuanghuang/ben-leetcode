/*
1528. Shuffle String

Level: Easy

https://leetcode.com/problems/shuffle-string
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
  string restoreString(string s, vector<int> &indices)
  {
    int n = s.size();
    char chars[n + 1];

    for (int i = 0; i < n; i++)
    {
      chars[indices[i]] = s[i];
    }
    chars[n] = 0;
    return string(chars);
  }
};

class Solution
{
public:
  string restoreString(string s, vector<int> &indices)
  {
    int i = 0;
    while (i < s.size())
    {
      // cout << i << endl;
      if (indices[i] == i)
      {
        ++i;
      }
      else
      {
        swap(s[i], s[indices[i]]);
        swap(indices[i], indices[indices[i]]);
      }
    }
    return s;
  }
};