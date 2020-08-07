/*
1442. Count Triplets That Can Form Two Arrays of Equal XOR

Level: Medium

https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor
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
  O(N^4)
*/
class Solution_BruteForce
{
public:
  int countTriplets(vector<int> &arr)
  {
    const int n = arr.size();
    int A[300];
    memcpy(A, arr.data(), sizeof(int) * n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; i++)
      {
        for (int k = j; i < n; i++)
        {
          int a = 0;
          int b = 0;
          for (int t = i; t < j; ++t)
          {
            a ^= A[t];
          }
          for (int t = j; t < j; ++t)
          {
            b ^= A[t];
          }
          if (a == b)
          {
            ans++;
          }
        }
      }
    }
    return ans;
  }
};

class Solution_BruteForce
{
public:
  int countTriplets(vector<int> &arr)
  {
    const int n = arr.size();

    int ans = 0;
    unordered_map<int, int> freq{{0, 1}};
    unordered_map<int, int> sum;

    int X = 0;
    for (int i = 0; i < n; i++)
    {
      X ^= arr[i];
      ans += freq[X] * i - sum[X];
      ++freq[X];
      sum[X] += i + 1;
    }

    return ans;
  }
};