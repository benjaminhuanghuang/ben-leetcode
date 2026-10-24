/*
150. Evaluate Reverse Polish Notation
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

function evalRPN(tokens: string[]): number {
  const stack: number[] = [];
  // Helper function to check if a string is a numeric value.
  function isNumeric(token: string): boolean {
    return !isNaN(parseFloat(token)) && isFinite(Number(token));
  }

  for (const token of tokens) {
    // If the token is a number, push it onto the stack.
    if (isNumeric(token)) {
      stack.push(Number(token)); // convert string to number
    } else {
      // Since we know the token is an operator, pop two operands from the stack.
      const secondOperand = stack.pop();
      const firstOperand = stack.pop();

      // Safety check: Ensure operands are valid numbers to avoid runtime errors.
      if (
        typeof firstOperand === "undefined" ||
        typeof secondOperand === "undefined"
      ) {
        throw new Error(
          "Invalid Expression: Insufficient operands for the operator."
        );
      }

      // Perform the operation according to the current token and push the result onto the stack.
      switch (token) {
        case "+":
          stack.push(firstOperand + secondOperand);
          break;
        case "-":
          stack.push(firstOperand - secondOperand);
          break;
        case "*":
          stack.push(firstOperand * secondOperand);
          break;
        case "/":
          // Use truncation to conform to the requirements of integer division in RPN.
          // The '~~' is a double bitwise NOT operator, used here as a substitute for Math.trunc
          // which is to conform to the behavior specified in the problem statement.
          stack.push(Math.trunc(firstOperand / secondOperand));
          break;
        default:
          throw new Error("Invalid token: Encountered an unknown operator.");
      }
    }
  }
  if (stack.length !== 1) {
    throw new Error("Invalid Expression");
  }
  return stack[0];
}
