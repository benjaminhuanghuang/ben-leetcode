/*
224. Basic Calculator

https://leetcode.com/problems/basic-calculator/

*/

/*
https://algo.monster/liteproblems/224
*/
function calculate(s: string): number {
  const stack: number[] = [];
  let currentSign = 1; // This will hold the current sign, 1 for '+' and -1 for '-'
  let result = 0; // This will accumulate the result of the arithmetic expression

  for (let i = 0; i < s.length; ++i) {
    // Skip spaces in the expression
    if (s[i] === " ") {
      continue;
    }

    // Update the sign for the next number
    if (s[i] === "+") {
      currentSign = 1;
    } else if (s[i] === "-") {
      currentSign = -1;
    } else if (s[i] === "(") {
      // Push the result and sign onto the stack before resetting them
      stack.push(result);
      stack.push(currentSign);
      result = 0;
      currentSign = 1;
    } else if (s[i] === ")") {
      // Pop the sign then the result from the stack and combine them
      result *= stack.pop() as number; // sign
      result += stack.pop() as number; // previous result
    } else {
      // Parse the number and aggregate the result
      let value = 0;
      let j = i;
      // Continue for all subsequent digits to form the full number
      for (; j < s.length && !isNaN(Number(s[j])) && s[j] !== " "; ++j) {
        value = value * 10 + (s[j].charCodeAt(0) - "0".charCodeAt(0));
      }
      result += currentSign * value; // Add the number to the result
      i = j - 1; // Update the outer loop's index after processing the number
    }
  }

  return result;
}

/*
+，- 说明当前数字结束了，计算结果并更新符号
括号只是改变“当前上下文”， 栈正好保存上下文
*/
function calculate_2(s: string): number {
  let result = 0;
  let sign = 1;
  let num = 0;
  const stack: number[] = [];

  for (let i = 0; i < s.length; i++) {
    const char = s[i];

    if (char >= "0" && char <= "9") {
      num = num * 10 + Number(char);
    } else if (char === "+") {
      result += sign * num;
      num = 0;
      sign = 1;
    } else if (char === "-") {
      result += sign * num;
      num = 0;
      sign = -1;
    } else if (char === "(") {
      stack.push(result);
      stack.push(sign);
      result = 0;
      sign = 1;
    } else if (char === ")") {
      result += sign * num;
      num = 0;

      result *= stack.pop()!; // sign
      result += stack.pop()!; // previous result
    }
  }

  result += sign * num;
  return result;
}

/*
Approach 2: Using a recursive function
*/
function calculate2(s: string): number {
  const stack: number[] = [];
  let number = 0; // This will hold the current number being parsed
  let currentSign = "+"; // This will hold the current sign;

  for (let i = 0; i < s.length; ++i) {
    // case1: Skip spaces in the expression
    if (s[i] === " ") {
      if (i === s.length - 1) {
        stack.push(number);
      }
      continue;
    }
    // case2: Parse the number
    if (/^\d$/.test(s[i])) {
      number = number * 10 + Number.parseInt(s[i]);
    }
    // case 3: Process (), see the content inside the parentheses as a number
    if (s[i] === "(") {
      let count = 0;
      const left = i;
      while (i < s.length) {
        if (s[i] === "(") {
          count++;
        } else if (s[i] === ")") {
          count--;
        }
        if (count === 0) {
          break;
        }
        i++;
      }
      number = calculate2(s.substring(left + 1, i));
    }
    // case4: Handle the + , -
    if ("+-".includes(s[i]) || i === s.length - 1) {
      if (currentSign === "+") {
        stack.push(number);
      } else if (currentSign === "-") {
        stack.push(-number);
      }
      currentSign = s[i];
      number = 0;
    }
  }

  return stack.reduce((acc, val) => acc + val, 0);
}

export { calculate, calculate2 };
