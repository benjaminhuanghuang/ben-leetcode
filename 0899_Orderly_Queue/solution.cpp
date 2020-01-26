/*
899. Orderly Queue

https://leetcode.com/problems/orderly-queue/

给了一个字符串和一个数字K，每次操作可以把字符串的前K个数字中任意抽取一个放到最后，可以做很多次操作。问，经过很多次操作之后，能构成的字母序最小的字符串是什么？
*/

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