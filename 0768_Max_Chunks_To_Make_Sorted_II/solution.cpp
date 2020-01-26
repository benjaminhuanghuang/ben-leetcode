/*
768. Max Chunks To Make Sorted II
https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
*/

#include <vector>
#include <numeric>

using namespace std;

/*
https://zxi.mytechroad.com/blog/algorithms/array/leetcode-768-max-chunks-to-make-sorted-ii/
Time complexity: O(nlogn)

Space complexity: O(n)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> v(arr.size());
    std::iota(v.begin(), v.end(), 0);
    std::sort(v.begin(), v.end(), [&arr](const int i1, const int i2){
      return arr[i1] == arr[i2] ? (i1 < i2) : arr[i1] < arr[i2];
    });
    int ans = 0;
    int m = 0;
    for (int i = 0; i < v.size(); ++i) {
      m = max(m, v[i]);
      if (m == i) ++ans;
    }
    return ans;
    }
};