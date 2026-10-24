#include <vector>
#include <string>

using namespace std;

/*
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1125-smallest-sufficient-team/
*/
class Solution
{
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        const int n = req_skills.size();
        const int target = (1 << n) - 1;

        vector<int> skills;
        for (const auto &p : people)
        {
            int mask = 0;
            for (const string &s : p)
                mask |= (1 << find(begin(req_skills), end(req_skills), s) - begin(req_skills));
            skills.push_back(mask);
        }

        vector<int> dp((1 << n), INT_MAX / 2);
        vector<pair<int, int>> pt((1 << n));
        dp[0] = 0;

        for (int i = 0; i < people.size(); ++i)
        {
            const int k = skills[i];
            if (k == 0)
                continue;
            for (int j = target; j >= 0; --j)
                if (dp[j] + 1 < dp[j | k])
                {
                    dp[j | k] = dp[j] + 1;
                    pt[j | k] = {j, i};
                }
        }

        int t = target;
        vector<int> ans;
        while (t)
        {
            ans.push_back(pt[t].second);
            t = pt[t].first;
        }
        return ans;
    }
};
