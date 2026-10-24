/*
1249. Minimum Remove to Make Valid Parentheses

https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

[Meta]
*/

function minRemoveToMakeValid(s: string): string {
  // Count how many '(' must be matched.
  const stack: number[] = [];
  const toRemove: Set<number> = new Set();
  // First pass to find indices of unmatched parentheses
  for (let i = 0; i < s.length; i++) {
    const char = s[i];
    if (char === "(") {
      stack.push(i);
    } else if (char === ")") {
      if (stack.length > 0) {
        stack.pop();
      } else {
        toRemove.add(i); // Add unmatched ) closing parentheses to the removal set
      }
    }
  }

  // Add any unmatched ( opening parentheses to the removal set
  while (stack.length > 0) {
    toRemove.add(stack.pop()!);
  }

  // Second pass to build the result string
  const result: string[] = [];
  for (let i = 0; i < s.length; i++) {
    if (!toRemove.has(i)) {
      result.push(s[i]);
    }
  }

  return result.join("");
}
