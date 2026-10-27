/*
Time complexity O(N^2)
Space complexity O(N)
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
