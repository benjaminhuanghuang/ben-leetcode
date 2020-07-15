/*
1163. Last Substring in Lexicographical Order

Level: Hard

https://leetcode.com/problems/last-substring-in-lexicographical-order
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

class Solution_bruteforce
{
public:
  string lastSubstring_bruteforce(string s)
  {
    string_view ans;
    for (int i = 0; i < s.length(); ++i)
      if (s.substr(i) > ans)
        ans = s.substr(i);
    return string(ans);
  }

  string lastSubstring_bruteforce2(string s)
  {
    double ex = 0.0, pre = 0.0;

    int idx = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {
      double cur = pre / 26.0 + s[i] - 'a';
      if (cur > ex)
      {
        ex = cur;
        idx = i;
      }
      pre = cur;
    }
    return s.substr(idx);
  }
};

/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution
{
public:
  string lastSubstring(string s)
  {
    //find the first index with the lexicographically biggest value
    int biggest = 0;
    for (int i = 1; i < s.size(); i++)
    {
      if (s[i] > s[biggest])
      {
        biggest = i;
      }
    }

    /*
        from that index onwards, find indices with the same letter
        if found, run a comparison of the two strings, indicated by:
        j represents the current maximum string (from [biggest, s.size()))
        j = [biggest, start_i)
        start_i is the index we just encountered
        i = [start_i, s.size())
        i represents the string that could be lexicographically larger
        
        */
    for (int i = biggest + 1; i < s.size(); i++)
    {
      if (s[i] == s[biggest])
      {
        int j = biggest;
        int start_i = i;
        //we keep incrementing i & j till they're in range and the chars at their place are equal
        while (i < s.size() && j < start_i && s[i] == s[j])
        {
          i++;
          j++;
        }

        //if i == s.size() ==> both strings are equal
        //if not, and j < start_i, that means we encountered a point of non-equality of chars
        //now if at this point, we encountered a char that is bigger, we have a new max_string
        //otherwise j==start_i and the previous string is already the biggest one

        if (i < s.size() && j < start_i)
        {
          if (s[i] > s[j])
          {
            biggest = start_i;
          }
        }
        i--;
      }
    }
    return s.substr(biggest);
  }
};