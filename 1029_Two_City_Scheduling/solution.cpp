// https://leetcode.com/problems/two-city-scheduling/
#include <vector>
#include <algorithm>

using namespace std;
/*
https://www.youtube.com/watch?v=3A98vh5zsqw&t=146s
*/
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        sort(begin(costs), end(costs), [](const auto &c1, const auto &c2) {
            return c1[0] - c1[1] < c2[0] - c2[1];
        });
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += i < n / 2 ? costs[i][0] : costs[i][1];
        }
        return ans;
    }
};