/*

Letter Combinations of a Phone Number


Talk-through: Backtracking, one digit at a time. Map each digit to its
letters, and at each recursion depth try every letter for the current digit:
append it, recurse into the next digit, then remove it (undo) before trying
the next letter. A full combination is recorded once the path's length
matches the number of digits.

Time big O of 4^n * n (up to 4 letters per digit), space big O of n for the
recursion stack.
*/
function letterCombinations(digits: string): string[] {
  if (digits.length === 0) return [];

  const letterMap: Record<string, string> = {
    "2": "abc",
    "3": "def",
    "4": "ghi",
    "5": "jkl",
    "6": "mno",
    "7": "pqrs",
    "8": "tuv",
    "9": "wxyz",
  };

  const result: string[] = [];
  const path: string[] = [];

  function backtrack(index: number): void {
    if (index === digits.length) {
      result.push(path.join(""));
      return;
    }

    const letters = letterMap[digits[index]];
    for (const letter of letters) {
      path.push(letter);
      backtrack(index + 1);
      path.pop();
    }
  }

  backtrack(0);
  return result;
}
