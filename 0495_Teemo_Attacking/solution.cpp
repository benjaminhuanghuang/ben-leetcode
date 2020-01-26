/*
495. Teemo Attacking

https://leetcode.com/problems/teemo-attacking/
*/
#include <vector>
#include <unordered_map>

using namespace std;

/*
https://zxi.mytechroad.com/blog/simulation/leetcode-495-teemo-attacking/

Idea: Running Process
Compare the current attack time with the last one, if span is more than duration, add duration to total, otherwise add (curr – last).
*/
class Solution
{
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration)
  {
    if (timeSeries.empty())
      return 0;
    int total = 0;
    for (int i = 1; i < timeSeries.size(); ++i)
      total += (timeSeries[i] > timeSeries[i - 1] + duration ? duration : timeSeries[i] - timeSeries[i - 1]);
    return total + duration;
  }
};