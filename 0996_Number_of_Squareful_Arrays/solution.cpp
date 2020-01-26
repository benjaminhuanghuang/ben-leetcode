/*
996. Number of Squareful Arrays

https://leetcode.com/problems/number-of-squareful-arrays/
*/

#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  https://zxi.mytechroad.com/blog/searching/leetcode-996-number-of-squareful-arrays/
  Solution: 
  Time complexity: O(n!)
  Space complexity: O(n)
*/


class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        
    }
};

/*
https://www.youtube.com/watch?v=V5eeRgQsr6o
*/
class Solution2  {
public:
    int numSquarefulPerms(vector<int>& A) {
        if (A.size() <= 1)
            return 0;
        vector<int> cur;
        vector<vector<int>> res;
        vector<bool> used(A.size(),false);
        // vector A must be sorted, the test case is not complete
        sort(A.begin(), A.end());
     
        dfs(A, res, cur, used);
        return res.size();
    }
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, vector<bool>& used) {
        if (cur.size() ==  nums.size()) {
            res.push_back(cur);            
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // prune的过程
            if (used[i] || (i > 0 && !used[i-1] && nums[i]==nums[i-1])) { 
                continue;
            }
            
            // check if it is a valid insert
            if (cur.size() > 0 && !isSquare(cur.back() + nums[i])) { 
                continue;
            }
            used[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, res, cur, used);
            
            // for backtracking in the next step
            cur.pop_back();
            used[i] = false;
        }
    }      
    bool isSquare(const int num) {
        if (num == 0 && num == 1)
            return true;
        int i = sqrt(num);
        return i * i == num;
    }
};