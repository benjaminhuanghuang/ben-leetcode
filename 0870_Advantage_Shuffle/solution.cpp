/*
870. Advantage Shuffle

https://leetcode.com/problems/advantage-shuffle/
*/

#include <vector>
#include <set>
#include <string>

using namespace std;

/*
https://zxi.mytechroad.com/blog/greedy/leetcode-870-advantage-shuffle/
Solution: Greedy 田忌赛马

Use the smallest unused number A[j] in A such that A[j] > B[i], if not possible, use the smallest number in A.

Time complexity: O(nlogn)

Space complexity: O(n)

*/
class Solution
{
public:
  vector<int> advantageCount(vector<int> &A, vector<int> &B)
  {
    multiset<int> s(begin(A), end(A));
    vector<int> ans;
    for (int b : B)
    {
      auto it = s.upper_bound(b);
      if (it == s.end())
        it = s.begin();
      ans.push_back(*it);
      s.erase(it);
    }
    return ans;
  }
};