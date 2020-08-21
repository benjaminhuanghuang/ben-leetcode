/*
1240. Tiling a Rectangle with the Fewest Squares

Level: Hard

https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares
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
  Solution: DFS

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1240-tiling-a-rectangle-with-the-fewest-squares/
*/

class Solution {
public:
  int tilingRectangle(int n, int m) {
   if (n > m) return tilingRectangle(m, n);
    int ans = n * m;    
    vector<int> h(n);
    function<void(int)> dfs = [&](int cur) {
      if (cur >= ans) return;
      
      auto it = min_element(begin(h), end(h));
      if (*it == m) { // All filled
        ans = cur;
        return;
      }
 
      int low = *it;
      int s = it - begin(h);
      int e = s;
      
      // Find the base
      while (e < n && h[e] == h[s] && (e - s + 1 + low) <= m) ++e;
      for (int i = --e; i >= s; --i) {
        // Try all possible square sizes in reverse order.
        int size = i - s + 1;
        for (int j = s; j <= i; ++j) h[j] += size;
        dfs(cur + 1);
        for (int j = s; j <= i; ++j) h[j] -= size;
      }
    };
    
    dfs(0);
    return ans;
  }
};