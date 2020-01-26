
/*
  
*/
 
#include <vector>
#include <unordered_map>
#include <assert.h> /* assert */

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> indies;
    for (int i = 0; i < nums.size(); i++)
    {
      indies[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++)
    {
      int diff = target -nums[i];
      if(indies.count(diff) && indies[diff] != i)
      {
        return {i, indies[diff]};
      }
    }
    // generalized initializer lists are a C++11 extension
    return {};
  }
};

int main()
{
  vector<int> nums {2, 7, 11, 15};

  Solution s;
  vector<int> res = s.twoSum(nums, 9);

  assert(res.size() == 2);
  assert(res[0] == 0);
  assert(res[1] == 1);

  return 0;
}