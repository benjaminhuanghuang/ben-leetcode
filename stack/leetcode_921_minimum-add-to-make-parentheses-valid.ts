/*
921. Minimum Add to Make Parentheses Valid

https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
*/

function minAddToMakeValid_stack(s: string): number {
  const stack = [];
  let answer = 0;
  for (const c of s) {
    if (c === "(") {
      stack.push(c);
    } else if (c === ")") {
      if (stack.length > 0) {
        stack.pop();
      } else {
        answer++;
      }
    }
  }
  return answer + stack.length;
}

function minAddToMakeValid(s: string): number {
  let balance = 0; // This will keep track of the balance between '(' and ')'
  let additions = 0; // Counter for the additions required to make the string valid

  // Loop through each character in the string
  for (let i = 0; i < s.length; i++) {
    const c = s[i];

    // If it's an opening bracket, increase the balance
    if (c === "(") {
      balance++;
    } else {
      // Implicitly c is ')', as it's not '('
      // If there is a matching opening bracket, decrement the balance
      if (balance > 0) {
        balance--;
      } else {
        // If there is no matching opening bracket, increment additions
        additions++;
      }
    }
  }

  // Add any unmatched opening brackets to the additions
  return (additions += balance);
}
