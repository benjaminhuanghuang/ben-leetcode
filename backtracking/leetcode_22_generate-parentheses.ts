/*
22. Generate Parentheses
https://leetcode.com/problems/generate-parentheses/
*/

/*
https://www.youtube.com/watch?v=7AtTtoq6W1E

N: N pairs of parentheses
*/

function generateParenthesis(n: number): string[] {
  const cur: string[] = [];
  const ans: string[] = [];

  // Number of '(' and ')'used so far.
  function backtrack(openN: number, closedN: number) {
    // When we have used n opening and n closing parentheses, we have a complete valid combination.
    if (openN === n && closedN === n) {
      ans.push(cur.join(""));
      return;
    }

    // If we still have '(' left to use, we add one, recurse, and then backtrack by removing it.
    if (openN < n) {
      cur.push("(");
      backtrack(openN + 1, closedN);
      cur.pop();
    }
    // add ')' if it doesn’t exceed the number of '(' already used.
    if (closedN < openN) {
      cur.push(")");
      backtrack(openN, closedN + 1);
      cur.pop();
    }
  }

  backtrack(0, 0);

  return ans;
}
