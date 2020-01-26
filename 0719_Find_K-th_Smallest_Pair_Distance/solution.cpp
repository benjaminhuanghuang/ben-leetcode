/*
719. Find K-th Smallest Pair Distance [Hard]

https://leetcode.com/problems/find-k-th-smallest-pair-distance/
*/

#include <vector>
using namespace std;

/*
https://zxi.mytechroad.com/blog/divide-and-conquer/leetcode-719-find-k-th-smallest-pair-distance/
*/
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums.back() - nums.front();
        while (l <= r) {
            int cnt = 0;
            int j = 0;
            int m = l + (r - l) / 2;
            for (int i = 0; i < n; ++i) {
                while (j < n && nums[j] - nums[i] <= m) ++j;
                cnt += j - i - 1;
            }
            cnt >= k ? r = m - 1 : l = m + 1;
        }        
        return l;
    }
};