/*
632. Smallest Range
https://leetcode.com/problems/smallest-range/
*/
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
Lai offer
https://www.youtube.com/watch?v=csJXQZFYklE
*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
    }
};

/*
http://bookshadow.com/weblog/2017/07/02/leetcode-smallest-range/
https://www.cnblogs.com/grandyang/p/7200016.html
Sliding Window
*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res;
        vector<pair<int, int>> v;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            for (int num : nums[i]) {
                v.push_back({num, i});
            }
        }
        sort(v.begin(), v.end());
        int left = 0, n = v.size(), k = nums.size(), cnt = 0, diff = INT_MAX;
        for (int right = 0; right < n; ++right) {
            if (m[v[right].second] == 0) ++cnt;
            ++m[v[right].second];
            while (cnt == k && left <= right) {
                if (diff > v[right].first - v[left].first) {
                    diff = v[right].first - v[left].first;
                    res = {v[left].first, v[right].first};
                } 
                if (--m[v[left].second] == 0) --cnt;
                ++left;
            }
        }
        return res;
    }
};
/*
priority_queue
https://www.cnblogs.com/grandyang/p/7200016.html
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int curMax = INT_MIN, n = nums.size();
        vector<int> idx(n, 0);
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {return a.first > b.first;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) > q(cmp);
        for (int i = 0; i < n; ++i) {
            q.push({nums[i][0], i});
            idx[i] = 1;
            curMax = max(curMax, nums[i][0]);
        }
        vector<int> res{q.top().first, curMax};
        while (idx[q.top().second] < nums[q.top().second].size()) {
            int t = q.top().second; q.pop();
            q.push({nums[t][idx[t]], t});
            curMax = max(curMax, nums[t][idx[t]]);
            ++idx[t];
            if (res[1] - res[0] > curMax - q.top().first) {
                res = {q.top().first, curMax};
            }
        }
        return res;
    }
};