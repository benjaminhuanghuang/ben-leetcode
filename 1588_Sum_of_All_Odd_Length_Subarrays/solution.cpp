/*
1588. Sum of All Odd Length Subarrays

Level: Easy

https://leetcode.com/problems/sum-of-all-odd-length-subarrays
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
#include <functional>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  Solution: 
*/

class Solution {
public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    const int n = arr.size();    
    int ans = 0;
    for (int i = 0, s = 0; i < n; ++i, s = 0)
      for (int j = i; j < n; ++j) {
        s += arr[j];
        ans += s * ((j - i + 1) & 1);
      }    
    return ans;
  }
};

/*
Solution 2: Math

Count how many times arr[i] can be in of an odd length subarray
we chose the start, which can be 0, 1, 2, … i, i + 1 choices
we chose the end, which can be i, i + 1, … n – 1, n – i choices
Among those 1/2 are odd length.
So there will be upper((i + 1) * (n – i) / 2) odd length subarrays contain arr[i]

ans = sum(((i + 1) * (n – i) + 1) / 2 * arr[i] for in range(n))

Time complexity: O(n)
Space complexity: O(1)

*/
class Solution {
public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    const int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans += ((i + 1) * (n - i) + 1) / 2 * arr[i];
    return ans;
  }
};