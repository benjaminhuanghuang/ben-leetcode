/*
Use a stack. For each char, if it forms a "bad pair" with the top of the
stack (same letter, opposite case), pop the top instead of pushing — that
mirrors removing both characters and lets a new bad pair with the
previous character surface naturally.

Time complexity: O(n)
Space complexity: O(n)
*/
function makeGood(s: string): string {
  const stack: string[] = [];

  for (const ch of s) {
    const top = stack[stack.length - 1];
    if (
      top !== undefined &&
      top !== ch &&
      top.toLowerCase() === ch.toLowerCase()
    ) {
      stack.pop();
    } else {
      stack.push(ch);
    }
  }

  return stack.join("");
}

export {};
