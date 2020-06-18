/*
1385. Find the Distance Value Between Two Arrays

Level: Easy

https://leetcode.com/problems/find-the-distance-value-between-two-arrays
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
  Time complexity: O(m*n)
  Space complexity: O(1)  
*/

class Solution
{
public:
  int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
  {
    int ans = 0;
    for (int x : arr1)
    {
      bool flag = true;
      for (int y : arr2)
      {
        if (abs(x - y) <= d)
        {
          flag = false;
          break;
        }
      }
      ans += flag; // if flag, ans ++
    }
    return ans;
  }

  /*
   
    Time complexity: O(mlogm + nlogn + m + n)
    Space complexity: O(1)
    */
  int findTheDistanceValue_v2(vector<int> &arr1, vector<int> &arr2, int d)
  {
    // Sort arr1 in ascending order and sort arr2 in descending order.
    sort(begin(arr1), end(arr1));
    sort(rbegin(arr2), rend(arr2));

    int ans = 0;
    for (int a : arr1)
    {
      while (arr2.size() && arr2.back() < a - d)
        arr2.pop_back();
      ans += arr2.empty() || arr2.back() > a + d;
    }
    return ans;
  }

  /*
    Sort arr2 in ascending order. and do two binary searches for each element to determine the range of [a-d, a+d], if that range is empty we increase the counter

    Time complexity: O(mlogm + nlogm)
    Space complexity: O(1)
    */
  int findTheDistanceValue_v3(vector<int> &arr1, vector<int> &arr2, int d)
  {
    sort(begin(arr2), end(arr2));
    int ans = 0;
    for (int a : arr1)
    {
      auto it1 = lower_bound(begin(arr2), end(arr2), a - d);
      auto it2 = upper_bound(begin(arr2), end(arr2), a + d);
      if (it1 == it2)
        ++ans;
    }
    return ans;
  }
};