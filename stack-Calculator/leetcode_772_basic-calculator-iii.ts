/*
772. Basic Calculator III

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
 

Note: Do not use the eval built-in library function.
*/
function calculate(s: string): number {
  const stack: number[] = [];
  let num: number = 0;
  let sign: string = "+";
  const n: number = s.length;

  for (let i = 0; i < n; i++) {
    const char: string = s[i];

    if (!isNaN(parseInt(char)) && char !== " ") {
      num = num * 10 + parseInt(char);
    }
    // calculate the expression inside the parentheses as a number
    if (char === "(") {
      let j = i,
        cnt = 0;
      for (; i < n; i++) {
        // Find the matching ')'
        if (s[i] === "(") cnt++;
        if (s[i] === ")") cnt--;
        if (cnt === 0) break;
      }
      num = calculate(s.substring(j + 1, i));
    }

    if (isNaN(parseInt(char)) || i === n - 1) {
      switch (sign) {
        case "+":
          stack.push(num);
          break;
        case "-":
          stack.push(-num);
          break;
        case "*":
          stack.push(stack.pop()! * num);
          break;
        case "/":
          stack.push(Math.trunc(stack.pop()! / num));
          break;
      }
      sign = char;
      num = 0;
    }
  }

  return stack.reduce((acc, val) => acc + val, 0);
}
