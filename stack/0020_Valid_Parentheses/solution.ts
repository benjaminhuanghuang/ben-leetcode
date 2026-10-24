/*
20. Valid Parentheses

https://leetcode.com/problems/valid-parentheses/description/
*/
function isValid(s: string): boolean {
  const stack: string[] = [];

  const map: Record<string, string> = {
    ")": "(",
    "]": "[",
    "}": "{",
  };

  for (const ch of s) {
    if (ch === "(" || ch === "[" || ch === "{") {
      stack.push(ch);
    } else {
      // ch is a closing bracket
      if (stack.length === 0) return false;

      const top = stack.pop();
      if (top !== map[ch]) return false;
    }
  }

  return stack.length === 0;
}
