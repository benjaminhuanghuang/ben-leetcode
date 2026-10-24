
/*
997. Find the Town Judge

https://leetcode.com/problems/find-the-town-judge/
*/
#include <vector>
using namespace std;

/*
[graph]

node with degree (in_degree – out_degree) N – 1 is the judge.
Time complexity: O(N+T)
Space complexity: O(N)

*/
class Solution
{
public:
  int findJudge(int N, vector<vector<int>> &trusts)
  {
    vector<int> degrees(N + 1); // N people, 1 to N
    for (const auto &trust : trusts)
    {
      --degrees[trust[0]];
      ++degrees[trust[1]];
    }
    for (int i = 1; i <= N; ++i)
      if (degrees[i] == N - 1)
        return i;
    return -1;
  }
};