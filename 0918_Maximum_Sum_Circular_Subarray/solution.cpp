/*
918. Maximum Sum Circular Subarray
https://leetcode.com/problems/maximum-sum-circular-subarray/
*/

#include <vector>
#include <algorithm>

using namespace std;

/*
https://linlaw0229.github.io/2018/10/22/918-Maximum-Sum-Circular-Subarray/
*/
class Solution
{
public:
  int maxSubarraySumCircular(vector<int> &A)
  {
    int nocircle = help(A), sum = 0;
    if (nocircle < 0)
      return nocircle;

    vector<int> tmp = A;
    for (auto &n : tmp)
    {
      sum += n;
      n *= -1;
    }

    int circle = sum + help(tmp);
    return max(circle, nocircle);
  }
  int help(vector<int> &A)
  {
    int max_endhere = 0, max_sofar = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
      if (max_endhere < 0)
        max_endhere = A[i];
      else
        max_endhere += A[i];

      max_sofar = max(max_sofar, max_endhere);
    }
    return max_sofar;
  }
};