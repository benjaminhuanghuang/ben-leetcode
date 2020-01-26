/*
1011. Capacity To Ship Packages Within D Days [Medium]

https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
  https://blog.csdn.net/fuxuemingzhu/article/details/88769103
  https://www.youtube.com/watch?v=t2eQB9-EqPg

  Solution:  Binary Search, find minimal valid ship weight capacity 
  [ #875. Koko Eating Bananas ]

*/
class Solution
{
public:
  int shipWithinDays(vector<int> &weights, int D)
  {
    int l = *max_element(weights.begin(), weights.end());
    int r = accumulate(weights.begin(), weights.end(), 0);
    while (l < r)
    {
      int mid = l + (r - l) / 2;
      int days = 1;
      int capacity = 0;
      for (auto const &w : weights)
      {
        if (capacity + w > mid)
        {
          days += 1;
          capacity = 0;
        }
        capacity += w;
      }
      if (days > D)
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
};