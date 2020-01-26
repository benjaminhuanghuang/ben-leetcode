package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
241. Different Ways to Add Parentheses

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2

Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

 */
public class LC_0241_DifferentWaystoAddParentheses {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> res = new ArrayList<>();
        // Base case.
        if (!containsOperator(input)) {
            res.add(Integer.parseInt(input));
            return res;
        }
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (c == '-' || c == '+' || c == '*') {
                String a = input.substring(0, i);
                String b = input.substring(i + 1);
                List<Integer> left = diffWaysToCompute(a);
                List<Integer> right = diffWaysToCompute(b);
                for (int x : left) {
                    for (int y : right) {
                        if (c == '-')
                            res.add(x - y);
                        else if (c == '+')
                            res.add(x + y);
                        else if (c == '*')
                            res.add(x * y);
                    }
                }
            }
        }
        return res;
    }
    private boolean containsOperator(String input) {
        if (input.length() == 0)
            return false;

        for (char ch : input.toCharArray()) {
            if (ch == '+' || ch == '-' || ch == '*')
                return true;
        }
        return false;
    }
}
