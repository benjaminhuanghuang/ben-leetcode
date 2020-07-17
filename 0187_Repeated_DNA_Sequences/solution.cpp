/*
187. Repeated DNA Sequences

Level: Medium

https://leetcode.com/problems/repeated-dna-sequences
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
  vector<string> findRepeatedDnaSequences(string s)
  {
    vector<string> ans;
    unordered_map<string, int> map;

    for (int index = 10; index <= s.size(); index++)
    {
      // 从第10位开始作为结尾，位移一位，比较一次子串
      string substr = s.substr(index - 10, 10); // key point
      if (map.count(substr))
      {
        // 如果是第一次遇到，则加入结果
        if (map[substr] == 1)
        {
          ans.push_back(substr);
        }
        map[substr]++;
      }
      else
      {
        // fist time
        map[substr]= 1;
      }
    }
    return ans;
  }
};