#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int findShortestSubArray(vector<int> &nums)
  {
    unordered_map<int, vector<int>> indices;
    for (int i = 0; i < nums.size(); ++i)
      indices[nums[i]].push_back(i);
      
    size_t degree = 0;
    for (const auto &p : indices)
      degree = max(degree, p.second.size());
    int ans = nums.size();
    for (const auto &p : indices)
    {
      if (p.second.size() != degree)
        continue;
      ans = min(ans, p.second.back() - p.second.front() + 1);
    }
    return ans;
  }
};