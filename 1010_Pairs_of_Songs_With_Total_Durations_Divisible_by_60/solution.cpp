/*
1010. Pairs of Songs With Total Durations Divisible by 60
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
*/
#include <vector>

using namespace std;

class Solution
{
public:
  int numPairsDivisibleBy60(vector<int> &time)
  {
    // 记录某个Durations（%60）有几首歌
    vector<int> counter(60);
    int ans = 0;
    for (int t : time)
    {
      t %= 60;
      // Do not use counter[60 - t] at this line, t can be 0
      ans += counter[(60 - t) % 60];
      ++counter[t];
    }
    return ans;
  }
};