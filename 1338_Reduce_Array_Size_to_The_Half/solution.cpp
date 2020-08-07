/*
1338. Reduce Array Size to The Half

Level: Medium

https://leetcode.com/problems/reduce-array-size-to-the-half
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
  int minSetSize(vector<int> &arr)
  {

    int halfLength = arr.size() / 2;
    unordered_map<int, int> count;
    for (int n : arr)
    {
      count[n]++;
    }
    vector<int> vec;
    for (auto kv : count)
    {
      vec.push_back(kv.second);
    }

    sort(vec.rbegin(), vec.rend());  // big to samll
    int res = 0, todelete = arr.size() / 2;
    for (auto n : vec)
    {
      todelete -= n;
      res++;
      if (todelete <= 0)
        break;
    }
    return res;
  }
};