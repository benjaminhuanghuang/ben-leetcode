/*
1052. Grumpy Bookstore Owner

https://leetcode.com/problems/grumpy-bookstore-owner/
*/
#include <vector>
using namespace std;
/*
https://zxi.mytechroad.com/blog/sliding-window/leetcode-1052-grumpy-bookstore-owner/

Solution: Sliding Window

Sum the costumers of non grumpy minutes, recording the max sum of the sliding window of size X.

Time complexity: O(n)
Space complexity: o(n)
*/

class Solution
{
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X)
  {
    int base = 0;
    int window = 0;
    int best_window = 0;
    for (int i = 0; i < grumpy.size(); ++i)
    {
      (grumpy[i] ? window : base) += customers[i];
      if (i >= X && grumpy[i - X])
        window -= customers[i - X];
      best_window = max(best_window, window);
    }
    return base + best_window;
  }
};