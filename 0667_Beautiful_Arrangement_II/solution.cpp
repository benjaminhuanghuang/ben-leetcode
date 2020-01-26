/*
667. Beautiful Arrangement II

https://leetcode.com/problems/beautiful-arrangement-ii/
*/
#include <vector>
using namespace std;

/*
https://www.cnblogs.com/grandyang/p/7577878.html
*/

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int i = 1, j = n;
        while (i <= j) {
            if (k > 1) res.push_back(k-- % 2 ? i++ : j--);
            else res.push_back(i++);
        }
        return res;
    }
};