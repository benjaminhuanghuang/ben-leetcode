/*
1460. Make Two Arrays Equal by Reversing Sub-arrays

Level: Easy

https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays
*/
#include <vector>
#include <string>
#include <unordered_map>

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
  bool canBeEqual(vector<int> &target, vector<int> &arr)
  {
    unordered_map<int, int> numbers;
    for (int i : target)
    {
      numbers[i]++;
    }
    for (int i : arr)
    {
      if (numbers[i] <= 0)
      {
        return false;
      }
      numbers[i]--;
    }
    return true;
  }
};