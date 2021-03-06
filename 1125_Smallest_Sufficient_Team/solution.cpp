/*
1125. Smallest Sufficient Team

https://leetcode.com/problems/smallest-sufficient-team/

In a project, you have a list of required skills req_skills, and a list of people.  The i-th person people[i] contains a list of skills that person has.

Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill.  We can represent these teams by the index of each person: for example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].

Return any sufficient team of the smallest possible size, represented by the index of each person.

You may return the answer in any order.  It is guaranteed an answer exists.

 

Example 1:

Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]

Example 2:

Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]


 */
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
