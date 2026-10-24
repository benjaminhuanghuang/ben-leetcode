/*
    18-(7+(2-4))
*/
function evaluateExpression(s: string): number {
  const stack: number[] = [];
  let currNum = 0;
  let sign = 1; // 1 for '+', -1 for '-'
  let res = 0;

  for (const c of s) {
    if (/\d/.test(c)) {
      // If c is number, build the current number
      currNum = currNum * 10 + parseInt(c);
    } else if (c === "+" || c === "-") {
      // add the current number multiplied by current sign
      res += currNum * sign;
      // update the sign
      sign = c === "-" ? -1 : 1;
      currNum = 0;
    } else if (c === "(") {
      // push the current result and sign onto the stack
      stack.push(res);
      stack.push(sign);
      // reset for the new nested expression
      res = 0;
      sign = 1;
    } else if (c === ")") {
      // finalize the current nested expression
      res += currNum * sign;
      currNum = 0;
      // apply the sign before adding to outer result
      const prevSign = stack.pop()!;
      const prevRes = stack.pop()!;
      res = prevRes + prevSign * res;
    }
  }

  // finalize the overall expression
  return res + currNum * sign;
}
/*
Time complexity: The time complexity of evaluate_expression is O(n) because we traverse each
character of the expression once, processing nested expressions using the stack, where each stack
push or pop operation takes O(1) time.

Space complexity: The space complexity is O(n) because the stack can grow proportionally to the
length of the expression.
*/
