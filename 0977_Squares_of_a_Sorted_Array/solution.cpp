/*
977. Squares of a Sorted Array

https://leetcode.com/problems/squares-of-a-sorted-array/
*/
#include <vector>
#include <cmath>

using namespace std;

/*
https://zxi.mytechroad.com/blog/two-pointers/leetcode-977-squares-of-a-sorted-array/

Solution: Two pointers + Merge two sorted arrays

Time complexity: O(n)
Space complexity: O(1)

对于负数，从右向左
对于正数，从左向右
*/

class Solution
{
public:
  vector<int> sortedSquares(vector<int> &A)
  {
    vector<int> ans(A.size());
    auto right = prev(end(A));
    auto left = begin(A);

    auto it = end(ans);
    while (--it >= begin(ans))
    {
      if (right > left && abs(*right) > abs(*left))
        *it = pow(*right--, 2);
      else
        *it = pow(*left++, 2);
    }
    return ans;
  }
};

class Solution
{
public:
  vector<int> sortedSquares(vector<int> &A)
  {
    vector<int> ans(A.size());
    int left = 0;
    int right = A.size() - 1;
    int i = A.size() - 1;
    while (i >= 0)
    {
      if ( right> left && abs(A[right]) > abs(A[left]))
      {
        ans[i] = A[right] * A[right];
        right --; 
      }
      else
      {
        ans[i] = A[left] * A[left];
        right --; 
      }
      i--;
    }
    return ans;
  }
};