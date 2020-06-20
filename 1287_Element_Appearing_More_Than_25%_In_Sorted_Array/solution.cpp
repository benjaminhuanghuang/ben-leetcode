/*
1287. Element Appearing More Than 25% In Sorted Array

Level: Easy

https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array
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
  int findSpecialInteger(vector<int> &arr)
  {
    unordered_map<int, int> counter;
    int count = arr.size();
    for (int i : arr)
    {
      counter[i]++;
      if (counter[i] > count / 4)
      {
        return i;
      }
    }
    return -1;
  }
  /*
  NOTE! array sorted in non-decreasing order, 
  */
  int findSpecialInteger_v2(vector<int> &arr)
  {
    int count = 1;
    for (int i = 0; i < arr.size() - 1; i++)
    {
      if (arr[i] != arr[i + 1])
      {
        if (count > arr.size() / 4)
        {
          return arr[i];
        }
        count = 1;
      }
      else
      {
        count++;
      }
    }

    return arr[arr.size() - 1];
  }
};