/*
726. Number of Atoms

https://leetcode.com/problems/number-of-atoms/

[Google]
*/

function countOfAtoms(formula: string): string {
  let i = 0;
  const len = formula.length;
  const stack: Array<Map<string, number>> = [];

  // push an empty map to the stack to count the atoms
  stack.push(new Map<string, number>());

  while (i < len) {
    if (formula[i] === "(") {
      stack.push(new Map<string, number>());
      i++;
    } else if (formula[i] === ")") {
      const top = stack.pop()!;
      let start = ++i;
      let num = 1;
      while (i < len && isDigit(formula[i])) i++;
      if (i > start) num = parseInt(formula.substring(start, i));
      for (const [key, value] of top) {
        const currentCount = stack[stack.length - 1].get(key) || 0;
        stack[stack.length - 1].set(key, currentCount + value * num);
      }
    } else {
      // start with upper case character
      let start = i++;
      while (i < len && isLowerCase(formula[i])) {
        // append lower case character to the name
        i++;
      }
      const name = formula.substring(start, i);
      start = i;
      while (i < len && isDigit(formula[i])) i++;
      const num = i > start ? parseInt(formula.substring(start, i)) : 1;
      const currentCount = stack[stack.length - 1].get(name) || 0;
      stack[stack.length - 1].set(name, currentCount + num);
    }
  }

  const map = stack.pop()!;
  const sortedKeys = Array.from(map.keys()).sort();
  const result = sortedKeys
    .map((key) => `${key}${map.get(key)! > 1 ? map.get(key) : ""}`)
    .join("");

  return result;
}

function isDigit(char: string): boolean {
  return /\d/.test(char);
}

function isLowerCase(char: string): boolean {
  return /[a-z]/.test(char);
}

/*
Huahua
Approach: String + Recursion
https://www.youtube.com/watch?v=6nQ2jfs7a7I
https://zxi.mytechroad.com/blog/string/leetcode-726-number-of-atoms/

*/

export { countOfAtoms };
