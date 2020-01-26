/*
936. Stamping The Sequence
https://leetcode.com/problems/stamping-the-sequence/
*/

#include <vector>
#include <string>

using namespace std;
/*
https://zxi.mytechroad.com/blog/greedy/leetcode-936-stamping-the-sequence/


*/
class Solution {
public:
  vector<int> movesToStamp(string stamp, string target) {
    vector<int> ans;
    vector<int> seen(target.length());
    int total = 0;
    while (total < target.length()) {      
      bool found = false;
      for (int i = 0; i <= target.length() - stamp.length(); ++i) {
        if (seen[i]) continue;
        int l = unStamp(stamp, target, i);
        if (l == 0) continue;
        seen[i] = 1;
        total += l;
        ans.push_back(i);
        found = true;
      }
      if (!found) return {};
    }
    reverse(begin(ans), end(ans));
    return ans;
  }
private:
  int unStamp(const string& stamp, string& target, int s) {    
    int l = stamp.size();
    for (int i = 0; i < stamp.length(); ++i) {
      if (target[s + i] == '?')
        --l;
      else if (target[s + i] != stamp[i])
        return 0;
    }
    
    if (l != 0)
      std::fill(begin(target) + s, begin(target) + s + stamp.length(), '?');
    return l;
  }
};