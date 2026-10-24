#include <vector>
#include <unordered_map>

using namespace std;

/*

https://zxi.mytechroad.com/blog/uncategorized/leetcode-1124-longest-well-performing-interval/
 convert tiring day to 1, non-tiring day to -1,
 Finde a subarray it's sum > 0 or == 1

*/

class Solution
{
public:
  int longestWPI(vector<int> &hours)
  {
    int sum = 0;
    unordered_map<int, int> idx; // sum(>0): index

    int ans = 0;
    for (int i = 0; i < hours.size(); ++i)
    {
      sum += hours[i] > 8 ? 1 : -1;
      if (sum > 0)
        ans = i + 1;
      else
      {
        if (!idx.count(sum))
          idx[sum] = i;
        if (idx.count(sum - 1))   // sum of(i,  idx[sum - 1]) is 1
          ans = max(ans, i - idx[sum - 1]);
      }
    }
    return ans;
  }
};

/*

*/
class Solution_Wrong
{
public:
  int longestWPI(vector<int> &hours)
  {
    int maxLen = 0;
    int tiringDayStart = -1;
    int tiringDayEnd = -1;
    int normalDayStart = -1;
    int normalDayEnd = -1;
    for (int i = 0; i < hours.size(); i++)
    {
      if (hours[i] == 0)
      {
        if (tiringDayStart >= 0)
          maxLen = max(maxLen, i - tiringDayStart);
        normalDayStart = -1;
        tiringDayStart = -1;
      }
      else if (hours[i] > 8)
      {
        if (tiringDayStart > tiringDayStart || tiringDayStart == -1)
        {
          if (tiringDayStart >= 0)
            maxLen = max(maxLen, i - tiringDayStart);
          normalDayStart = i;
          tiringDayStart = i;
        }
      }
      else
      {
        if (normalDayStart == tiringDayStart)
        {
          normalDayStart = i;
        }
      }
    }
    if (hours[hours.size() - 1] > 0 && tiringDayStart > 0)
    {
      maxLen = max(maxLen, int(hours.size() - 1 - tiringDayStart));
    }
    return maxLen;
  }
};