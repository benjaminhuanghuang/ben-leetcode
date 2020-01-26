package cn.huang.leetcode;

import java.util.Stack;

/*
150. Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

    Division between two integers should truncate toward zero.
    The given RPN expression is always valid. That means the expression would always evaluate to a result and there
    won't be any divide by zero operation.

Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation:
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22



 */
public class LC_0150_EvaluateReversePolishNotation
{
    public int evalRPN(String[] tokens) {
        Stack<Integer> myStack = new Stack<Integer>();
        for (String t:tokens)
        {
            switch (t)
            {
                case "+":
                    int operandplus1 = myStack.pop();
                    int operandplus2 = myStack.pop();

                    int resultplus = operandplus1 + operandplus2;
                    myStack.push(resultplus);
                    break;
                case "-":
                    int operandmun1 = myStack.pop();
                    int operandmun2 = myStack.pop();

                    int resultmun = operandmun2 - operandmun1;
                    myStack.push(resultmun);
                    break;
                case "*":
                    int operandmul1 = myStack.pop();
                    int operandmul2 = myStack.pop();

                    int resultmul = operandmul1 * operandmul2;
                    myStack.push(resultmul);
                    break;
                case "/":
                    int operanddiv1 = myStack.pop();
                    int operanddiv2 = myStack.pop();

                    int resultdiv = operanddiv2 / operanddiv1;
                    myStack.push(resultdiv);
                    break;
                default:
                    myStack.push(Integer.parseInt(t));
                    break;
            }
        }

        return myStack.pop();
    }
}
