/*
412. Fizz Buzz

Level: Easy

https://leetcode.com/problems/fizz-buzz
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
  vector<string> fizzBuzz(int n)
  {
    vector<string> ans;

    for (int i = 1; i <= n; i++)
    {
      if (i % 3 == 0 && i % 5 == 0)
      {
        ans.push_back("FizzBuzz");
      }
      else if (i % 5 == 0)
      {
        ans.push_back("Buzz");
      }
      else if (i % 3 == 0)
      {
        ans.push_back("Fizz");
      }
      else{
        ans.push_back(to_string(i));
      }
    }
    return ans;
  }
};