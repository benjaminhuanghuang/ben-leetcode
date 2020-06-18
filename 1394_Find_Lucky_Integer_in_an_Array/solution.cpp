/*
1394. Find Lucky Integer in an Array

Level: Easy

https://leetcode.com/problems/find-lucky-integer-in-an-array
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

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
  int findLucky_v1(vector<int> &arr)
  {
    unordered_map<int, int> counter;

    for (int i : arr)
    {
      counter[i]++;
    }

    int luckNum = -1;
    unordered_map<int, int>::iterator it = counter.begin();
    // Iterate over the map using Iterator till end.
    while (it != counter.end())
    {
      if (it->first == it->second)
      {
        if (it->first > luckNum)
        {
          luckNum = it->first;
        }
      }
    }
    return luckNum;
  }

  int findLucky(vector<int> &arr)
  {
    map<int, int> counter;
    int lucky = -1;

    for (int i : arr)
    {
      counter[i]++;
    }

    for (auto const &elem : counter)
    {
      if (elem.first == elem.second)
        lucky = elem.first;
    }

    return lucky;
  }
};