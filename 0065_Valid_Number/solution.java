package cn.huang.leetcode;

/*
65. Valid Number

Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
 */
public class LC_0065_ValidNumber {
    /*
    https://www.youtube.com/watch?v=1Xa6cVCzFBg
     */
    public boolean isNumber(String s) {
        s = s.trim();
        boolean hasSign = false;
        boolean hasDot = false;
        boolean hasE = false;
        boolean hasNumber = false;

        for (char ch : s.toCharArray()) {
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

            if (!Character.isDigit(ch)) {
                //除了数字，只能接受以上字符：e . + -
                return false;
            }

            hasNumber = true;
        }

        return hasNumber;
    }
}
