#include <string>
using namespace std;

/*
https://zxi.mytechroad.com/blog/string/leetcode-899-orderly-queue/

Solution: Rotation or Sort?

if 𝑘=1, we can only rotate the string.

if 𝑘>1, we can bubble sort the string.

Time complexity: O(n^2)

Space complexity: O(n)
 */
class Solution
{
public:
    string orderlyQueue(string S, int K)
    {
        if (K > 1)
        {
            sort(begin(S), end(S));
            return S;
        }

        string ans = S;
        for (int i = 1; i < S.size(); ++i)
            ans = min(ans, S.substr(i) + S.substr(0, i));
        return ans;
    }
};