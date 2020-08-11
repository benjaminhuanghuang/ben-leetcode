/*
17. Letter Combinations of a Phone Number

https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        vector<vector<char>> digitMap(10);
        digitMap[0] = {' '};
        digitMap[1] = {};
        digitMap[2] = {'a', 'b', 'c'};
        digitMap[3] = {'d', 'e', 'f'};
        digitMap[4] = {'g', 'h', 'i'};
        digitMap[5] = {'j', 'k', 'l'};
        digitMap[6] = {'m', 'n', 'o'};
        digitMap[7] = {'p', 'q', 'r', 's'};
        digitMap[8] = {'t', 'u', 'v'};
        digitMap[9] = {'w', 'x', 'y', 'z'};
        string cur;
        vector<string> ans;
        dfs(digits, digitMap, 0, cur, ans);
        return ans;
    }

private:
    void dfs(const string &digits,
             const vector<vector<char>> &digitMap,
             int pos, string &combination, vector<string> &ans)
    {
        // base case
        if (pos == digits.length())
        {
            ans.push_back(combination);
            return;
        }
        // recursive rule
        for (const char c : digitMap[digits[pos] - '0'])
        {
            combination.push_back(c);
            dfs(digits, digitMap, pos + 1, combination, ans);
            combination.pop_back();
        }
    }
};

class Solution_BFS
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        vector<vector<char>> d(10);
        d[0] = {' '};
        d[1] = {};
        d[2] = {'a', 'b', 'c'};
        d[3] = {'d', 'e', 'f'};
        d[4] = {'g', 'h', 'i'};
        d[5] = {'j', 'k', 'l'};
        d[6] = {'m', 'n', 'o'};
        d[7] = {'p', 'q', 'r', 's'};
        d[8] = {'t', 'u', 'v'};
        d[9] = {'w', 'x', 'y', 'z'};
        vector<string> ans{""};
        for (char digit : digits)
        {
            vector<string> tmp;
            for (const string &s : ans)
                for (char c : d[digit - '0'])
                    tmp.push_back(s + c);
            // ans = tmp
            ans.swap(tmp);
        }
        return ans;
    }
};