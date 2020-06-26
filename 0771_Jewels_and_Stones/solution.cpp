/*
771. Jewels and Stones

Level: Easy

https://leetcode.com/problems/jewels-and-stones
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
  int numJewelsInStones(string J, string S)
  {
    int res = 0;
    unordered_set<char> s;
    for (char c : J)
      s.insert(c);
    for (char c : S)
    {
      if (s.count(c))
        ++res;
    }
    return res;
  }


  int numJewelsInStones_slow(string J, string S)
  {
    int count = 0;
    for (int i = 0; i < J.size(); i++)
    {
      for (int j = 0; j < S.size(); j++)
      {
        if (J[i] == S[j])
          count++;
        else
          continue;
      }
    }
    return count;
  }

  int numJewelsInStones_v2(string J, string S)
  {
    int count = 0;
    for (int i = 0; i < S.length(); i++)
    {
      if (J.find(S[i]) != std::string::npos)
        count++;
    }
    return count;
  }
};