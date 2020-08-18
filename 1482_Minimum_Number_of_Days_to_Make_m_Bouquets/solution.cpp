/*
1482. Minimum Number of Days to Make m Bouquets

Level: Medium

https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  Solution: 

  https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-1482-minimum-number-of-days-to-make-m-bouquets/

*/

class Solution {
public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    const auto [lo, hi] = minmax_element(begin(bloomDay), end(bloomDay));
    const int kInf = *hi + 1;
    int l = *lo;
    int r = kInf;
    
    // Return the number of bouquets we can get at day D.
    auto getBouquets = [&](int D) {
      int ans = 0;
      int cur = 0;
      for (int d : bloomDay) {
        if (d > D) {
          cur = 0;
        } else if (++cur == k) {
          ++ans;
          cur = 0;          
        }
      }
      return ans;
    };
          
    while (l < r) {
      int mid = l + (r - l) / 2;      
      // Find smallest day that bouquets >= m.
      if (getBouquets(mid) >= m)
        r = mid;
      else
        l = mid + 1;
    }
    return l >= kInf ? -1 : l;
  }
};