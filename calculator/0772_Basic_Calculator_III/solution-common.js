/*
通用递归下降解析器，支持 +、-、*、/、()、空格、一元正负号

语法（优先级从低到高）：
  AddSub -> MulDiv (('+' | '-') MulDiv)*
  MulDiv -> Value (('*' | '/') Value)*
  Value  -> ('+' | '-') Value | '(' AddSub ')' | number

一元 +/- 显式在 Value 层处理：不管它出现在表达式开头、'(' 之后，
还是 '*'/'/' 之后，都在这一层被消费并处理，不依赖任何隐式技巧。
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
