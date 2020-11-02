/*
636. Exclusive Time of Functions

Level: Medium

https://leetcode.com/problems/exclusive-time-of-functions
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
  http://zxi.mytechroad.com/blog/string/leetcode-636-exclusive-time-of-functions/

  Solution: 
*/

class Solution
{
public:
  vector<int> exclusiveTime(int n, vector<string> &logs)
  {
    vector<int> ans(n, 0);
    char action[6];
    int fid;
    int curr;
    int prev;
    stack<int> s;
    for (const string &log : logs)
    {
      sscanf(log.c_str(), "%d:%[a-z]:%d", &fid, action, &curr);
      if (action[0] == 's')
      {
        if (!s.empty())
          ans[s.top()] += curr - prev;
        s.push(fid);
        prev = curr;
      }
      else
      { //end
        ans[s.top()] += curr - prev + 1;
        s.pop();
        prev = curr + 1;
      }
    }
    return ans;
  }
};