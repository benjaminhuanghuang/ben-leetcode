#include <string>
#include <vector>
using namespace std;

/*
https://zxi.mytechroad.com/blog/string/leetcode-553-optimal-division/

  最大的情况一直都是A[0] / ( A[1] / A[2] / ... / A[N-1] )
*/
class Solution
{
public:
  string optimalDivision(vector<int> &nums)
  {
    string ans = to_string(nums[0]);
    if (nums.size() == 1)
      return ans;
    else if (nums.size() == 2)
      return ans + "/" + to_string(nums[1]);

    ans += "/(" + to_string(nums[1]);
    for (int i = 2; i < nums.size(); ++i)
      ans += "/" + to_string(nums[i]);
    ans += ")";
    return ans;
  }
};