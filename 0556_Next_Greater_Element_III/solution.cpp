/*
556. Next Greater Element III

https://leetcode.com/problems/next-greater-element-iii/
*/
#include <string>
#include <climits>

using namespace std;

/*
https://blog.csdn.net/fuxuemingzhu/article/details/82113731

和31. Next Permutation解题方式基本一样，先找到从后向前数，第一个降序的位置，把此位置后面的翻转。
再把这个降序数字和后面第一个比它大的位置交换即可。
 */

class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.size(), i = len - 1;
        for (; i > 0; --i) {
            if (str[i] > str[i - 1]) break;
        }
        if (i == 0) return -1;
        for (int j = len - 1; j >= i; --j) {
            if (str[j] > str[i - 1]) {
                swap(str[j], str[i - 1]);
                break;
            }
        }
        sort(str.begin() + i, str.end());
        long long res = stoll(str);
        return res > INT_MAX ? -1 : res;
    }
};