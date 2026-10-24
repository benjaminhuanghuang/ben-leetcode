/*
89. Gray Code

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code.
A gray code sequence must begin with 0.

https://leetcode.com/problems/gray-code/
*/
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_DFS
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> res;
        unordered_set<int> set;
        helper(n, set, 0, res);
        return res;
    }
    void helper(int n, unordered_set<int> &set, int curr, vector<int> &res)
    {
        if (!set.count(curr))
        {
            set.insert(curr);
            res.push_back(curr);
        }
        for (int i = 0; i < n; ++i)
        {
            int t = curr;
            if ((t & (1 << i)) == 0)
                t |= (1 << i);   // i 位变成 1
            else
                t &= ~(1 << i);  // i 位变成 0
            if (set.count(t))
                continue;
            helper(n, set, t, res);
            break;
        }
    }
};
/*
https://www.youtube.com/watch?v=3h7SC3UiDwY

G(i) = i ^ (i/2)
*/
class Solution_Formula
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> res;
        for (int i = 0; i < 1 << n; i++)
        {
            res.push_back(i ^ i >> 1);
        }

        return res;
    }
};