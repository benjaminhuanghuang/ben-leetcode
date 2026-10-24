function validParenthesisExpression(s: string): boolean {
  const parenthesesMap: Record<string, string> = {
    "(": ")",
    "{": "}",
    "[": "]",
  };

  const stack: string[] = [];

  for (const c of s) {
    // If current character is an opening parenthesis, push it to the stack
    if (c in parenthesesMap) {
      stack.push(c);
    } else {
      // If it's a closing parenthesis, check if it matches the top of the stack
      if (stack.length > 0 && parenthesesMap[stack[stack.length - 1]] === c) {
        stack.pop();
      } else {
        return false;
      }
    }
  }

  // Return true only if all parentheses were closed
  return stack.length === 0;
}
