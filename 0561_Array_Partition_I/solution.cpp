/*
561. Array Partition I

https://leetcode.com/problems/array-partition-i/
*/
#include <vector>

using namespace std;

/*
  https://zxi.mytechroad.com/blog/hashtable/leetcode-561-array-partition-i/

  使每一个pair中的两个数尽量接近，这样就不会浪费掉较大的数
  Time complexity: O(nlogn)
  Space complexity: O(1)
*/

class Solution {
public:
  int arrayPairSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int ans = 0;
    for(int i = 0; i < nums.size(); i += 2)
        ans += nums[i];
    return ans;
  }
};