#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <numeric>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
  if (nums.size() == 0 || k <= 0 || t < 0)
    return false;

  multiset<int> s; // smallest to largest by default.

  for (int i = 0; i < nums.size(); ++i)
  {
    if (nums.size() == 0 || k <= 0 || t < 0)
      return false;

    multiset<int> s;

    for (int i = 0; i < nums.size(); ++i)
    {
      auto ceil = s.lower_bound(nums[i]); // first element that is not less than val.
      if (ceil != s.end() && (long)*ceil - nums[i] <= t)
        return true;

      if (ceil != s.begin())
      {
        auto floor = prev(ceil); //  smaller than val.
        if (floor != s.end() && nums[i] - (long)*floor <= t)
          return true;
      }
      s.insert(nums[i]);

      if (i >= k)
      {
        s.erase(nums[i - k]);
      }
    }
    return false;
  }
}

int main()
{
  vector<int> input = {1, 5, 9, 1, 5, 9};
  auto ans = containsNearbyAlmostDuplicate(input, 2, 3);
  cout << ans << endl;
  return 0;
}