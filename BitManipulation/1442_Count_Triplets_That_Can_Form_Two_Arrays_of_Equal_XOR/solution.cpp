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
        for (int k = j; k < n; k++)
        {
          int a = 0;
          int b = 0;
          for (int t = i; t < j; ++t)
          {
            a ^= A[t];
          }
          for (int t = j; t <= k; ++t)
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

/*
  Solution: Brute force + Prefix
  O(N^3)
  利用 b ^ b ^ a = 0 ^ a = a

  A[i] ^ ..... A[j] 
    = (A[0] ^ ..... A[i-1]) ^ (A[0] ^ ..... A[i-1]) ^ (A[i] ^ ..... A[j])
    = (A[0] ^ ..... A[i]) ^ (A[0] ^ ..... A[j])

*/
class Solution_BruteForce2
{
public:
  int countTriplets(vector<int> &arr)
  {
    const int n = arr.size();
    int ans = 0;
    vector<int> xors(n + 1);

    // xors [i] = A[0] ^.....A[i-1]
    for (int i = 0; i < n; i++)
    {
      xors[i + 1] = xors[i] ^ arr[i];
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; i++)
      {
        for (int k = j; k < n; k++)
        {
          int a = xors[j] ^ xors[i];
          int b = xors[k + 1] ^ xors[j];
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

/*
  Solution:  Prefix, Tuple to Pair
  O(N^2)
  利用 a = b => a ^ b == 0

  A[i] ^ ..... A[k] == 0 

*/
class Solution3
{
public:
  int countTriplets(vector<int> &arr)
  {
    const int n = arr.size();
    int ans = 0;
    vector<int> xors(n + 1);

    // xors [i] = A[0] ^.....A[i-1]
    for (int i = 0; i < n; i++)
    {
      xors[i + 1] = xors[i] ^ arr[i];
    }

    for (int i = 0; i < n; i++)
    {
      for (int k = i+1; k < n; k++)
      {
        if (xors[k + 1] == xors[i])
        {
          ans += k - i;
        }
      }
    }
    return ans;
  }
};

class Solution
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