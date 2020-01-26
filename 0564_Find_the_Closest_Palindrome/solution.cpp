/*
564. Find the Closest Palindrome
https://leetcode.com/problems/find-the-closest-palindrome/
 */

#include <string>
#include <unordered_set>
#include <climits>

using namespace std;

/*
https://www.cnblogs.com/grandyang/p/6915355.html
 */
class Solution {
public:
    string nearestPalindromic(string n) {
        long len = n.size(), num = stol(n), res, minDiff = LONG_MAX;
        unordered_set<long> s;
        s.insert(pow(10, len) + 1);
        s.insert(pow(10, len - 1) - 1);
        long prefix = stol(n.substr(0, (len + 1) / 2));
        for (long i = -1; i <= 1; ++i) {
            string pre = to_string(prefix + i);
            string str = pre + string(pre.rbegin() + (len & 1), pre.rend());
            s.insert(stol(str));
        }
        s.erase(num);
        for (auto a : s) {
            long diff = abs(a - num);
            if (diff < minDiff) {
                minDiff = diff;
                res = a;
            } else if (diff == minDiff) {
                res = min(res, a);
            }
        }
        return to_string(res);
    }
};