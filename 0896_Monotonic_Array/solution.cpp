/*
896. Monotonic Array
https://leetcode.com/problems/monotonic-array/
*/

#include <vector>
using namespace std;

/*
https://zxi.mytechroad.com/blog/algorithms/array/leetcode-896-monotonic-array/
*/
class Solution
{
public:
  bool isMonotonic(vector<int> &A)
  {
    bool inc = true;
    bool dec = true;

    for (int i = 1; i < A.size(); ++i)
    {
      inc &= A[i] >= A[i - 1];
      dec &= A[i] <= A[i - 1];
    }

    return inc || dec;
  }
};