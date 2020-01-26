package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
282. Expression Add Operators

Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators
(not unary) +, -, or * between the digits so they evaluate to the target value.

Example 1:

Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"]

Example 2:

Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]

Example 3:

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]

Example 4:

Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]

Example 5:

Input: num = "3456237490", target = 9191
Output: []

 */
public class LC_0282_ExpressionAddOperators {
    /*

This problem can be solved using DFS algorithm. For example, given the input “123456“, suppose we encounter the
last digit “6”, at which we already have the result of solve(“12345“). Then there are three cases:

solve(“123456”) = solve(“12345”) + 6

solve(“123456”) = solve(“12345”) – 6

solve(“123456”) = cal( solve(“12345”) , 6, *), this have the following three cases:

    suppose solve(“12345”) = solve(“1234”) + 5,  so we have solve(“123456”) = solve(“1234“) + 5 * 6
    suppose solve(“12345”) = solve(“123”) + 4  * 5,  so we have solve(“123456”) = solve(“123“) + 4 * 5 * 6
    suppose solve(“12345”) = solve(“1234”)  –  5,  so we have solve(“123456”) = solve(“1234“) - 5 * 6.

From the above three cases , we can see that in the step of solve(“123456“), we already have solve(“12345“), we also need to have the value of solve(“1234“), and 5 for case 1, 3; and solve(“123”) and 4*5 for case 2.

In the above case 1, we define preSum = solve(“1234”) + 5, and preVal = 5, then we have solve(“1234”) = solve(“12345”) – 5 = preSum – preVal.

In the above case 2, we define preSum = solve(“123”) + 4*5 ,and preVal = 4 * 5, then we have solve(“123”) = solve(“12345”) – 4*5 = preSum – preVal.

in the above case 3, we define preSum = solve(“1234”) – 5, and preVal = -5, then we have solve(“1234”) = solve(“12345”) – (-5) = preSum – preVal.

So in the recursive process, we need to track the preSum, and preVal based on the operators. See the following Java implementation for details.
     */
    public List<String> addOperators(String num, int target) {
        List<String> res = new ArrayList<>();
        solve(0, num.toCharArray(), "", 0, 0, target, res);
        return res;
    }

    void solve(int curIndex, char[] input, String curRes, long preSum, long preVal, int target, List<String> resSet) {
        if (curIndex == input.length) {
            if (preSum == target) {
                resSet.add(curRes);
            }
            return;
        }
        long curVal = input[curIndex] - '0';
        curVal = 0;
        for (int i = curIndex; i < input.length; i++) {
            curVal = curVal * 10 + (input[i] - '0');
            if (i > curIndex && input[curIndex] == '0') return;
            if (curIndex == 0) { // the first digit
                solve(i + 1, input, curRes + curVal, curVal, curVal, target, resSet);
            } else {
                //if(i > curIndex && input[curIndex - 1] == '0' && input[curIndex] == '0') return; not work
                //if( i > curIndex && input[curIndex] == '0') return; not work
                //case +
                solve(i + 1, input, curRes + "+" + curVal, preSum + curVal, curVal, target, resSet);
                //case -
                solve(i + 1, input, curRes + "-" + curVal, preSum - curVal, 0 - curVal, target, resSet);
                //case *
                solve(i + 1, input, curRes + "*" + curVal, preSum - preVal + preVal * curVal, preVal * curVal, target, resSet);
            }
        }
    }
}
