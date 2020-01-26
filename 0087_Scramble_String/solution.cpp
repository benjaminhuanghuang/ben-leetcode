/*
87. Scramble String

https://leetcode.com/problems/scramble-string/
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.empty() || s2 .empty())
            return false;
        if (s1==s2)
            return true;

        vector<int> letters(26);
        int len = s1.length();

        for (int i = 0; i < len; i++) {
            letters[s1[i] - 'a']++;
            letters[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (letters[i] != 0)
                return false;
        }

        for (int i = 1; i < len; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))
                return true;
        }
        return false;
    }
};