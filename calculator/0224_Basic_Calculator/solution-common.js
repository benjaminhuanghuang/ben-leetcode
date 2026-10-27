/*
+, -,(,) 和空格，没有 *,/。
*/

var calculate = function (s) {
  let i = 0;
  const n = s.length;

  function skipSpaces() {
    while (i < n && s[i] === " ") i++;
  }

  // 处理加法、减法
  function calculateAddSub() {
    let res = parseValue();

    while (true) {
      skipSpaces();

      if (i >= n || (s[i] !== "+" && s[i] !== "-")) {
        break;
      }

      const op = s[i++];
      const num = parseValue();

      if (op === "+") {
        res += num;
      } else {
        res -= num;
      }
    }

    return res;
  }

  // 读取数字，或者进入括号递归
  function parseValue() {
    skipSpaces();

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
