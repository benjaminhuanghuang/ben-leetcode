/*
1051. Height Checker

https://leetcode.com/problems/height-checker/
*/

#include <vector>
using namespace std;
/*
Solution: Sorting

Time complexity: O(nlogn)
Space complexity: O(n)
*/
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> h(heights);
        sort(begin(h), end(h));
        int ans = 0;
        for (int i = 0; i < h.size(); ++i)
            ans += (heights[i] != h[i]);
        return ans;
    }
};