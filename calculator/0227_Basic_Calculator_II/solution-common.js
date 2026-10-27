/*
+、-、*、/

核心思路：先计算乘除法，再计算加减法。
*/

var calculate = function (s) {
  let i = 0;
  const n = s.length;

  function skipSpaces() {
    while (i < n && s[i] === " ") {
      i++;
    }
  }

  // 处理加法、减法
  function calculateAddSub() {
    let res = calculateMulDiv();

    while (i < n) {
      skipSpaces();

      if (i >= n) break;

      const op = s[i];

      if (op !== "+" && op !== "-") break;

      i++;
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

    while (i < n) {
      skipSpaces();

      if (i >= n) break;

      const op = s[i];

      if (op !== "*" && op !== "/") break;

      i++;
      const num = parseValue();

      if (op === "*") {
        res *= num;
      } else {
        res = Math.trunc(res / num);
      }
    }

    return res;
  }

  // 读取数字
  function parseValue() {
    skipSpaces();

    let num = 0;

    while (i < n && s[i] >= "0" && s[i] <= "9") {
      num = num * 10 + Number(s[i]);
      i++;
    }

    return num;
  }

  return calculateAddSub();
};
