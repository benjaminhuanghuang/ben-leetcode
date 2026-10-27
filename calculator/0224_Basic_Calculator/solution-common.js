/*
递归下降解析器，支持 +、-、()、空格、一元正负号
没有 * /，所以只有两层：AddSub -> Value（没有 MulDiv 这一层）

语法（优先级从低到高）：
  AddSub -> Value (('+' | '-') Value)*
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
    let res = parseValue(); // start from a left operator

    while (true) {
      skipSpaces();

      if (i >= n || (s[i] !== "+" && s[i] !== "-")) {
        break;
      }

      const op = s[i++];
      const right_operator = parseValue();
      res = op === "+" ? res + right_operator : res - right_operator;
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

export { calculate };
