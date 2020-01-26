/*
42. Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water/
*/
#include <vector>

using namespace std;
 /*

  https://www.youtube.com/watch?v=8BHqSdwyODs
  每个位置所能存的水由 左边的最高值 和 右边的最高值 决定

  https://www.youtube.com/watch?v=2LjNzbK2cmA
  当前单元能装多少水是取决于左右两边挡板最小值与当前值之差。之后就用双指针更新左右挡板就好了。
*/
  
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;

        int leftMax = 0;
        int rightMax = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(height[left], leftMax);
                res += leftMax - height[left];
                left++;   // move left pointer
            } else {
                rightMax = max(height[right], rightMax);
                res += rightMax - height[right];
                right--;
            }
        }
        return res;
    }
};