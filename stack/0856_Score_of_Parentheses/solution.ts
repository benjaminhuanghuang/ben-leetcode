/*
856. Score of Parentheses

https://leetcode.com/problems/score-of-parentheses/

- 394. Decode String
*/

/*
Time complexity: O(N)

Space complexity: O(n)

push '(' into the stack, 
when ')' is encountered, pop the stack and calculate the sum of the numbers inside the ()
*/
function scoreOfParentheses(s: string): number {
  const stack: string[] = [];

  for (let i = 0; i < s.length; i++) {
    if (s[i] === ")") {
      const top = stack.pop();
      if (top === "(") {
        stack.push("1"); // () is 1
      } else {
        // can only be number
        let num = Number(top);
        // calculate the sum of the numbers inside the ()
        while (stack.length && !isNaN(Number(stack[stack.length - 1]))) {
          num += Number(stack.pop());
        }
        // pop the corresponding (
        stack.pop();
        stack.push((num * 2).toString()); //(num) is 2 * num
      }
    } else {
      stack.push(s[i]);
    }
  }

  return stack.reduce((acc, cur) => acc + Number(cur), 0);
}
