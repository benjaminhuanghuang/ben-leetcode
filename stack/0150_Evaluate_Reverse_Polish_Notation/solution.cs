/*
150. Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

using System.Collections.Generic;

public class Solution150 {
    public int EvalRPN(string[] tokens) {
       var myStack = new Stack<int>();
        foreach (var t in tokens)
        {
            switch (t)
            {
                case "+":
                    var operandplus1 = myStack.Pop();
                    var operandplus2 = myStack.Pop();

                    var resultplus = operandplus1 + operandplus2;
                    myStack.Push(resultplus);
                    break;
                case "-":
                    var operandmun1 = myStack.Pop();
                    var operandmun2 = myStack.Pop();

                    var resultmun = operandmun2 - operandmun1;
                    myStack.Push(resultmun);
                    break;
                case "*":
                    var operandmul1 = myStack.Pop();
                    var operandmul2 = myStack.Pop();

                    var resultmul = operandmul1 * operandmul2;
                    myStack.Push(resultmul);
                    break;
                case "/":
                    var operanddiv1 = myStack.Pop();
                    var operanddiv2 = myStack.Pop();

                    var resultdiv = operanddiv2 / operanddiv1;
                    myStack.Push(resultdiv);
                    break;
                default:
                    myStack.Push(int.Parse(t));
                    break;
            }
        }

        return myStack.Pop(); 
    }
}