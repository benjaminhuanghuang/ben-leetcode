/*
394. Decode String
https://leetcode.com/problems/decode-string/


Input: s = "3[a]2[bc]"
Output: "aaabcbc"

- 856. Score of Parentheses
*/

/*
    Category the characters into 4 groups:
    1. Digits: 0-9
    2. Open Bracket: [,  push the current number and string to the stack
    3. Close Bracket: ], pop the number and string from the stack and calculate
    4. Letters: a-z, A-Z
*/
function decodeString(s: string): string {
  const stack: string[] = [];
  let num = 0;
  let str = "";

  for (const char of s) {
    if (char === "[") {
      stack.push(str);
      stack.push(String(num));
      num = 0;
      str = "";
    } else if (char === "]") {
      const num = Number(stack.pop());
      const prevStr = stack.pop();
      str = prevStr + str.repeat(num); // Repeat the string
    } else if (char >= "0" && char <= "9") {
      num = num * 10 + Number(char);
    } else {
      str += char;
    }
  }
  return str;
}
