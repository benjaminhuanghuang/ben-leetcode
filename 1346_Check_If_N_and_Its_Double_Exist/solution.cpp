/*
1346. Check If N and Its Double Exist

Level: Easy

https://leetcode.com/problems/check-if-n-and-its-double-exist
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
  bool checkIfExist(vector<int> &arr)
  {
    unordered_set<int> set;
    for (int a : arr)
    {
      if (set.count(a * 2) || (a % 2 == 0 && set.count(a / 2)))
        return true;
      set.insert(a);
    }
    return false;
  }
};