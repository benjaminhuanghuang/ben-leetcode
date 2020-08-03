/*
1534. Count Good Triplets

Level: Easy

https://leetcode.com/problems/count-good-triplets
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
  int countGoodTriplets(vector<int> &arr, int a, int b, int c)
  {
    const int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        for (int k = j + 1; k < n; ++k)
          if (abs(arr[i] - arr[j]) <= a &&
              abs(arr[j] - arr[k]) <= b &&
              abs(arr[i] - arr[k]) <= c)
            ++ans;
    return ans;
  }
};