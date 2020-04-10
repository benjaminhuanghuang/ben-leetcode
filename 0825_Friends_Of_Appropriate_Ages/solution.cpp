/*
825. Friends Of Appropriate Ages
https://leetcode.com/problems/friends-of-appropriate-ages/
*/
#include <vector>
#include <unordered_set>

using namespace std;

/*
https://zxi.mytechroad.com/blog/hashtable/leetcode-825-friends-of-appropriate-ages/
Time complexity: O(n)
Space complexity: O(120)

age[B] > 100 && age[A] < 100 是冗余条件
*/
class Solution
{
public:
  int numFriendRequests(vector<int> &ages)
  {
    const int kMaxAge = 120;
    vector<int> counts(kMaxAge + 1, 0);
    // Count how many people at each age i
    for (const int age : ages)
      ++counts[age];

    int ans = 0;
    for (int A = 1; A <= kMaxAge; ++A)
    {
      for (int B = 0.5 * A + 7 + 1; B <= A; ++B)
        ans += counts[A] * (counts[B] - (A == B));
    }
    return ans;
  }
};