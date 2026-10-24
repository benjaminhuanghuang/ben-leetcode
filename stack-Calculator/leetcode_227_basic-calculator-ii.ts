/*
227. Basic Calculator II

https://leetcode.com/problems/basic-calculator-ii/

+ - * /
*/

/*
  使用一个栈保存数字，如果该数字之前的符号是+，把当前数字压入栈中，如果是-，则加入当前数字的相反数，
  如果之前的符号是乘或除，那么从栈顶取出一个数字和当前数字进行乘或除的运算，再把结果压入栈中，
  完成一遍遍历后，所有的乘或除都运算完了，再把栈中所有的数字都加起来
*/
function calculate(s: string): number {
  let res: number = 0;
  let num: number = 0;
  const n: number = s.length;
  let op: string = "+"; // track the current operator, initialize to '+'
  const st: number[] = [];

  for (let i = 0; i < n; ++i) {
    // parse the number
    if (s[i] >= "0") {
      num = num * 10 + parseInt(s[i]);
    }
    // operator or the last number
    if ((s[i] < "0" && s[i] !== " ") || i === n - 1) {
      if (op === "+") st.push(num);
      if (op === "-") st.push(-num);
      if (op === "*" || op === "/") {
        let tmp: number =
          op === "*"
            ? st[st.length - 1] * num
            : Math.trunc(st[st.length - 1] / num);
        st.pop();
        st.push(tmp);
      }
      op = s[i];
      num = 0;
    }
  }

  // Add all numbers in the stack
  while (st.length > 0) {
    res += st.pop()!;
  }

  return res;
}

export {};
