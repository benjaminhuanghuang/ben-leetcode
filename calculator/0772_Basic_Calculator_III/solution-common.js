/*
parseExpr()：处理 +、-
parseTerm()：处理 *、/
parseFactor()：处理数字、括号、一元正负号


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

      if (op === "+") {
        res += num;
      } else {
        res -= num;
      }
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

      if (op === "*") {
        res *= num;
      } else {
        res = Math.trunc(res / num);
      }
    }

    return res;
  }

  // 读取基本值：数字、括号表达式、一元正负号
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
      i++; // 跳过左括号
      const res = calculateAddSub();
      skipSpaces();
      i++; // 跳过右括号
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
