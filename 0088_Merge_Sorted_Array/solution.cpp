/*
88. Merge Sorted Array

[#21]
*/
#include <vector>
using namespace std;

/* 

  Solution
  Time complexity O(m+n) 
  Space complexity O(1)

*/

class Solution
{
public:
  void merge(vector<int> &A, int m, vector<int> &B, int n)
  {
    // From end to start
    int ia = m - 1, ib = n - 1, icur = m + n - 1;
    while (ia >= 0 && ib >= 0)
    {
      A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
    }
    // if A is logner, just keep it
    // if B is longer, move elements into A
    while (ib >= 0)
    {
      A[icur--] = B[ib--];
    }
  }
};