/*
954. Array of Doubled Pairs
https://leetcode.com/problems/array-of-doubled-pairs/
*/
#include <vector>
#include <unordered_map>

using namespace std;
/*
https://zxi.mytechroad.com/blog/hashtable/leetcode-954-array-of-doubled-pairs/

Time complexity: O(NlogN)
Space complexity: O(N)
*/

class Solution
{
public:
  bool canReorderDoubled(vector<int> &A)
  {
    unordered_map<int, int> c;
    for (int a : A)
      ++c[a];
    vector<int> keys;
    for (const auto &kv : c)
      keys.push_back(kv.first);
    sort(begin(keys), end(keys), [](int a, int b) { return abs(a) < abs(b); });
    for (int key : keys)
      if (c[key] && (c[key * 2] -= c[key]) < 0)
        return false;
    return true;
  }
};