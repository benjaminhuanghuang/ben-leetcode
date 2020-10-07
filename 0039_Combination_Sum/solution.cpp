/*
39. Combination Sum

https://leetcode.com/problems/combination-sum/
*/

#include <vector>
#include <algorithm>

using namespace std;

/*
https://zxi.mytechroad.com/blog/searching/leetcode-39-combination-sum/
*/
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> cur;
        // 
        std::sort(candidates.begin(), candidates.end());

        dfs(candidates, target, 0, cur, ans);
        return ans;
    }

private:
    void dfs(vector<int> &candidates, int target, int pos, vector<int> &cur, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(cur);
            return;
        }
        
        for (int i = pos; i < candidates.size(); ++i)
        {
            if (candidates[i] > target)  // 
                break;
            cur.push_back(candidates[i]);
            // 因为可以使用重复元素，所以继续从i开始， normal combination use i + 1
            dfs(candidates, target - candidates[i], i, cur, ans);
            cur.pop_back();
        }
    }
};