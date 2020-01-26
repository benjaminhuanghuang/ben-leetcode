/*
915. Partition Array into Disjoint Intervals
https://leetcode.com/problems/partition-array-into-disjoint-intervals/
*/

#include <vector>
#include <algorithm>

using namespace std;

/*
https://zxi.mytechroad.com/blog/greedy/leetcode-915-partition-array-into-disjoint-intervals/
*/
class Solution
{
public:
  int partitionDisjoint(vector<int> &A)
  {
    int left_max = A[0];
    int cur_max = A[0];
    int left_len = 1;
    for (int i = 1; i < A.size(); ++i)
    {
      if (A[i] < left_max)
      {
        left_max = cur_max;
        left_len = i + 1;
      }
      else
      {
        cur_max = max(cur_max, A[i]);
      }
    }
    return left_len;
  }
};