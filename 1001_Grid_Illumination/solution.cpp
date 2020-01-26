/*
1001. Grid Illumination

https://leetcode.com/problems/grid-illumination/

*/

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>

using namespace std;

/*
  https://zxi.mytechroad.com/blog/hashtable/leetcode-1001-grid-illumination/
  Solution: 
*/

class Solution {
public:
  vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    unordered_set<long> s;
    unordered_map<int, int> lx, ly, lp, lq;
    for (const auto& lamp : lamps) {
      const int x = lamp[0];
      const int y = lamp[1];
      s.insert(static_cast<long>(x) << 32 | y);
      ++lx[x];
      ++ly[y];
      ++lp[x + y];
      ++lq[x - y];
    }
    vector<int> ans;
    for (const auto& query : queries) {
      const int x = query[0];
      const int y = query[1];      
      if (lx.count(x) || ly.count(y) || lp.count(x + y) || lq.count(x - y)) {
        ans.push_back(1);       
        for (int tx = x - 1; tx <= x + 1; ++tx)
          for (int ty = y - 1; ty <= y + 1; ++ty) {
            if (tx < 0 || tx >= N || ty < 0 || ty >= N) continue;
            const long key = static_cast<long>(tx) << 32 | ty;
            if (!s.count(key)) continue;
            s.erase(key);
            if (--lx[tx] == 0) lx.erase(tx);
            if (--ly[ty] == 0) ly.erase(ty);
            if (--lp[tx + ty] == 0) lp.erase(tx + ty);
            if (--lq[tx - ty] == 0) lq.erase(tx - ty);
          }
      } else {
        ans.push_back(0);
      }
    }
    return ans;
  }
};