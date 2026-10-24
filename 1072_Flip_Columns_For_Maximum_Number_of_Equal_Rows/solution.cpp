#include <vector>
#include <string>
#include <unordered_map>

#include <algorithm>


using namespace std;

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        unordered_map<string, int> mapping;
        for (auto &row : matrix)
        {
            string ele = "";
            for (auto &val : row)
            {
                ele += val == row[0] ? '0' : '1';
            }
            mapping[ele]++;
        }
        int ans = 0;
        for (auto &[key, val] : mapping)
        {
            ans = max(ans, val);
        }
        return ans;
    }
};