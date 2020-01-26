/*
65. Valid Number
https://leetcode.com/problems/valid-number/s
*/
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        while(s[0]==' ')  s.erase(0,1);//delete the  prefix whitespace 
        while(s[s.length()-1]==' ') s.erase(s.length()-1, 1);//delete the suffix whitespace
       
        bool hasSign = false;
        bool hasDot = false;
        bool hasE = false;
        bool hasNumber = false;

        for (char ch : s) {
            if (ch == '.' && !hasDot && !hasE) {
                hasDot = true;
                continue;
            }

            if ((ch == 'e' || ch == 'E') && !hasE && hasNumber) {
                hasE = true;
                hasDot = false;
                hasNumber = false;
                hasSign = false;
                continue;
            }

            if ((ch == '+' || ch == '-') && !hasSign && !hasNumber && !hasDot) {
                hasSign = true;
                continue;
            }

            if (!isdigit(ch)) {
                //除了数字，只能接受以上字符：e . + -
                return false;
            }

            hasNumber = true;
        }

        return hasNumber;
    }
};