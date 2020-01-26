/*
526. Beautiful Arrangement

https://leetcode.com/problems/beautiful-arrangement/
*/
#include <vector>

using namespace std;

class Solution
{
public:
  int countArrangement(int N)
  {
    int ans = 0;
    vector<int> visited(N + 1, 0); // N integers from 1 to N.
    helper(N, visited, 1, ans);
    return ans;
  }

private:
  void helper(int N, vector<int> &visited, int start, int &ans)
  {
    if (start > N)
    {
      ++ans;
      return;
    }
    for (int i = 1; i <= N; ++i)
    {
      if (visited[i] == 0 && (i % start == 0 || start % i == 0))
      {
        visited[i] = 1;
        helper(N, visited, start + 1, ans);
        visited[i] = 0;
      }
    }
  }
};