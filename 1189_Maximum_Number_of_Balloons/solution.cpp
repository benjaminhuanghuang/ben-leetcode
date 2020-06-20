/*
1189. Maximum Number of Balloons

Level: Easy

https://leetcode.com/problems/maximum-number-of-balloons
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
  int maxNumberOfBalloons(string text)
  {
    unordered_map<char, int> counter;

    for (char c : text)
    {
      counter[c]++;
    }

    int count = 0;
    while (counter['b'] > 0)
    {
      // for (char c : "balloon")    // '\0' in "balloon" cause error
      for (char c : string("balloon"))  
      {
        if (counter[c] <=0)
        {
          return count;
        }
        counter[c]--;
      }
      count++;
    }
    return count;
  }
};