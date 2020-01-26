/*
985. Sum of Even Numbers After Queries

https://leetcode.com/problems/sum-of-even-numbers-after-queries/
*/
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
  {
    int sum = 0;
    for (int i = 0; i < A.size(); ++i)
      if (A[i] % 2 == 0)
        sum += A[i];
    vector<int> ans;
    for (const auto &query : queries)
    {
      int &a = A[query[1]];
      if (a % 2 == 0)
        sum -= a;
      a += query[0];
      if (a % 2 == 0)
        sum += a;
      ans.push_back(sum);
    }
    return ans;
  }
};