/*
60. Permutation Sequence

https://leetcode.com/problems/permutation-sequence
*/

#include <string>
#include <vector>

using namespace std;

/*
http://bangbingsyb.blogspot.com/2014/11/leetcode-permutation-sequence.html

以n = 4，k = 9为例,
最高位可以取{1, 2, 3, 4}，而每个数重复3! = 6次。所以第k=9个permutation的s[0]为{1, 2, 3, 4}中的第9/6+1 = 2个数字s[0] = 2。

而对于以2开头的6个数字而言，k = 9是其中的第k' = 9%(3!) = 3个。而剩下的数字{1, 3, 4}的重复周期为2! = 2次。
所以s[1]为{1, 3, 4}中的第k'/(2!)+1 = 2个，即s[1] = 3。

对于以23开头的2个数字而言，k = 9是其中的第k'' = k'%(2!) = 1个。剩下的数字{1, 4}的重复周期为1! = 1次。所以s[2] = 1.

对于以231开头的一个数字而言，k = 9是其中的第k''' = k''/(1!)+1 = 1个。s[3] = 4
*/

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string ret;
        vector<int> factorial(n, 1);
        vector<char> num(n, 1);

        for (int i = 1; i < n; i++)
            factorial[i] = factorial[i - 1] * i;

        for (int i = 0; i < n; i++)
            num[i] = (i + 1) + '0';

        k--;
        for (int i = n; i >= 1; i--)
        {
            int j = k / factorial[i - 1];
            k %= factorial[i - 1];
            ret.push_back(num[j]);
            num.erase(num.begin() + j);
        }

        return ret;
    }
};