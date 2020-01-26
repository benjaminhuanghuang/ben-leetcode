/*
398. Random Pick Index
https://leetcode.com/problems/random-pick-index/
*/
#include <vector>
#include <random>

using namespace std;

/*
https://zxi.mytechroad.com/blog/algorithms/array/leetcode-398-random-pick-index/

Solution: Reservoir sampling
https://en.wikipedia.org/wiki/Reservoir_sampling

Time complexity: O(query * n)
Space complexity: O(1)
*/

class Solution
{
public:
  Solution(vector<int> nums)
  {
    nums_ = std::move(nums);
  }

  int pick(int target)
  {
    int n = 0;
    int index = -1;
    for (int i = 0; i < nums_.size(); ++i)
    {
      if (nums_[i] != target)
        continue;
      // Reservoir sampling
      ++n;
      if (rand() % n == 0)
        index = i;
    }
    return index;
  }

private:
  vector<int> nums_;
};