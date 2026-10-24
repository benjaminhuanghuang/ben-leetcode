#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int end =0;
        int i = 0;
        while(i < nums.size())
        {
          if(nums[i] != val)
          {
            nums[end] = nums[i];
            end++;
          }
          i++;
        }
        return end;
    }
};