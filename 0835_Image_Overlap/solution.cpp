/*
835. Image Overlap
https://leetcode.com/problems/image-overlap/
*/

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

/*
https://www.cnblogs.com/grandyang/p/10355589.html
*/
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int res = 0, n = A.size();
        vector<vector<int>> listA, listB;
        unordered_map<string, int> diffCnt;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 1) listA.push_back({i, j});
                if (B[i][j] == 1) listB.push_back({i, j});
            }
        }
        for (auto a : listA) {
            for (auto b : listB) {
                ++diffCnt[to_string(a[0] - b[0]) + "-" + to_string(a[1] - b[1])];
            }
        }
        for (auto diff : diffCnt) {
            res = max(res, diff.second);
        }
        return res;
    }
};