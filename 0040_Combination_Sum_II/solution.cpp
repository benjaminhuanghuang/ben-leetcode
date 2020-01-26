/*
40. Combination Sum II

Each number in candidates may only be used once in the combination.
Input: candidates = [10,1,2,7,6,1,5], target = 8, There are two 1s
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
https://leetcode.com/problems/combination-sum-ii/
*/

#include <vector>
#include <set>

using namespace std;

/*
http://zxi.mytechroad.com/blog/searching/leetcode-40-combination-sum-ii/

Use set to remove duplicates
*/
class Solution_Set {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        std::sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(candidates, target, 0, ans, curr);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
private:
    void dfs(const vector<int>& candidates, 
             int target, int s, 
             set<vector<int>>& ans,              
             vector<int>& curr) {
        if (target == 0) {
            ans.insert(curr);
            return;
        }
        
        for (int i = s; i < candidates.size(); ++i) {
            int num = candidates[i];
            if (num > target) return;
            curr.push_back(num);
            dfs(candidates, target - num, i + 1, ans, curr);
            curr.pop_back();
        }
    }
};

/*
Disallow same numbber in same depth to remove duplicates
*/ 
class Solution_Vector {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        std::sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(candidates, target, 0, ans, curr);
        return ans;
    }
private:
    void dfs(const vector<int>& candidates, 
             int target, int s, 
             vector<vector<int>>& ans,              
             vector<int>& curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = s; i < candidates.size(); ++i) {
            int num = candidates[i];
            if (num > target) return;
            if (i > s && candidates[i] == candidates[i - 1]) 
            { 
              // i > s means this element is not the first ones
              continue;
            }
            curr.push_back(num);
            dfs(candidates, target - num, i + 1, ans, curr);
            curr.pop_back();
        }
    }
};