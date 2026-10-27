# Calculator

- LC 224 Basic Calculator: +, - , ()
- LC 227 Basic Calculator II: +, -, *, /
- LC 772 Basic Calculator III: +, -, *, /, ()

## Talking point

Opening（先说思路，别动笔）"The idea is recursive descent. An expression has two levels of precedence, so I write two functions. One handles plus and minus, one handles multiply and divide. Each one calls the level below it."
"Think of it as a grammar. AddSub is built from MulDiv terms, and MulDiv is built from single values. The lower the function, the tighter it binds. That's why multiplication gets computed first — it's deeper in the call chain."

"First, a helper to skip spaces, so I don't repeat that everywhere."
"parseValue reads one value. If it sees a plus or minus sign first, that's a unary sign — it belongs to this value, so I handle it here, recursively. Otherwise I read the full number digit by digit."
"calculateMulDiv gets a value, then while the next operator is times or divide, it takes the next value and folds it in immediately."
"calculateAddSub does the same one level up, with plus and minus."
"The main function just calls calculateAddSub once."

"For division, the problem asks to truncate toward zero, so I use Math.trunc. In JavaScript, minus three divided by two must give minus one, not minus two."
"Unary signs can appear at the start, or right after an operator, like three times minus two. Handling them inside parseValue covers both cases with one rule."

Complexity: "Time is O of n. There is one shared index that only moves forward, so every character is read once. Space is O of one extra — I don't keep a stack of numbers, just the three function layers on the call stack."

Test: "Let me test it. 'Three plus two times two' — I expect seven, because the two times two folds first. 'Three plus five divided by two' — five divided by two truncates to two, so five. Both pass."

Follow up
加括号？→ "I add one branch in parseValue: on an opening parenthesis, I call calculateAddSub recursively and skip the closing one. The rest doesn't change — that's why I picked this structure."

为什么不用 number stack？→ "The stack version is shorter for this problem alone. Recursive descent matches the grammar, so it extends without restructuring."

## Recursive Descent Parser

一种自顶向下（top-down）的语法解析方法，为语法中每一条"规则"（优先级层级）写一个对应的函数，函数之间按优先级从低到高逐层调用（recursive descent = 递归地往下钻）。

对应到计算器的例子：

语法规则：AddSub -> MulDiv -> Value（加减法由乘除法构成，乘除法由数字/括号构成）

每条规则对应一个函数：calculateAddSub()、calculateMulDiv()、parseValue()

每个函数开始时都先调用优先级更高（更底层）的函数去拿到一个完整的子结果，再处理自己这一层的运算符

"递归下降"是说 函数调用链从最低优先级一路"下降"到最高优先级（最基本的数字/括号），再把结果一层层"返回"上来参与上层运算。

外层函数（AddSub）对应优先级低的运算符，调用链最先进入它，但它必须先把内层（MulDiv）完全算完拿到一个值，才能做自己这层的加减——这就保证了乘除法天然先于加减法被求值。

## 通用模板

三题共用同一套递归下降结构，但各自只保留题目支持的分支，不留无用代码：

- 0224（+ - ()）：`AddSub -> Value`，不含 MulDiv
- 0227（+ - * /）：`AddSub -> MulDiv -> Value`，不含 `()`
- 0772（+ - * / ()）：`AddSub -> MulDiv -> Value`，含 `()`

一元 `+`、`-` 统一在 `parseValue` 层处理。下面是最完整的 0772 版本：

```js
/*
通用递归下降解析器，支持 +、-、*、/、()、空格、一元正负号

语法（优先级从低到高）：
  AddSub -> MulDiv (('+' | '-') MulDiv)*
  MulDiv -> Value (('*' | '/') Value)*
  Value  -> ('+' | '-') Value | '(' AddSub ')' | number
*/

var calculate = function (s) {
  let i = 0;
  const n = s.length;

  function skipSpaces() {
    while (i < n && s[i] === " ") i++;
  }

  // 处理加法、减法
  function calculateAddSub() {
    let res = calculateMulDiv();

    while (true) {
      skipSpaces();

      if (i >= n || (s[i] !== "+" && s[i] !== "-")) {
        break;
      }

      const op = s[i++];
      const num = calculateMulDiv();
      res = op === "+" ? res + num : res - num;
    }

    return res;
  }

  // 处理乘法、除法
  function calculateMulDiv() {
    let res = parseValue();

    while (true) {
      skipSpaces();

      if (i >= n || (s[i] !== "*" && s[i] !== "/")) {
        break;
      }

      const op = s[i++];
      const num = parseValue();
      res = op === "*" ? res * num : Math.trunc(res / num);
    }

    return res;
  }

  // 读取基本值：一元正负号、括号表达式、数字
  function parseValue() {
    skipSpaces();

    if (s[i] === "+") {
      i++;
      return parseValue();
    }

    if (s[i] === "-") {
      i++;
      return -parseValue();
    }

    if (s[i] === "(") {
      i++; // 跳过 '('
      // ()里是任意完整的表达式（包含加减乘除），必须从最低优先级 calculateAddSub 重新进入
      const res = calculateAddSub();
      skipSpaces();
      i++; // 跳过 ')'
      return res;
    }

    let num = 0;
    while (i < n && s[i] >= "0" && s[i] <= "9") {
      num = num * 10 + Number(s[i]);
      i++;
    }

    return num;
  }

  return calculateAddSub();
};
```
