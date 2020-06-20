/*
1309. Decrypt String from Alphabet to Integer Mapping

Level: Easy

https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping
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
  string freqAlphabets(string s)
  {
    string ans;
    int i = 0;
    while (i < s.size())
    {
      if (i + 2 < s.size() && s[i + 2] == '#')
      {
        int n = stoi(s.substr(i, 2));
        ans += (char)(n - 10 + 'j');
        i += 3;
      }
      else
      {
        int n = stoi(s.substr(i, 1));
        ans += (char)(n - 1 + 'a');
        i += 1;
      }
    }
    return ans;
  }
};