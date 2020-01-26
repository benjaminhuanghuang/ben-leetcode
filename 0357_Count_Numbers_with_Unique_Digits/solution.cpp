/*
357. Count Numbers with Unique Digits

https://leetcode.com/problems/count-numbers-with-unique-digits/

*/
#include <vector>

using namespace std;

/*
https://zxi.mytechroad.com/blog/math/leetcode-357-count-numbers-with-unique-digits/
*/
class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        vector<int> f(11);
        f[1] = 10;
        f[2] = 9 * 9;
        for (int i = 3; i <= 10; ++i)
            f[i] = f[i - 1] * (10 - i + 1);
        int ans = 0;
        for (int i = 0; i <= min(10, n); ++i)
            ans += f[i];
        return ans;
    }
};