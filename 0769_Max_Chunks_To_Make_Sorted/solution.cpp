/*
769. Max Chunks To Make Sorted
https://leetcode.com/problems/max-chunks-to-make-sorted/
*/

#include <vector>
#include <numeric>

using namespace std;
/*
https://zxi.mytechroad.com/blog/difficulty/medium/leetcode-769-max-chunks-to-make-sorted/
题目大意：给你一个0 ~ n-1的排列，问你最多能分成几组，每组分别排序后能够组成0 ~ n-1。
*/
class Solution
{
public:
  int maxChunksToSorted(vector<int> &arr)
  {
    int ans = 0;
    int m = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
      m = max(m, arr[i]);
      if (m == i)
        ++ans;
    }
    return ans;
  }
};