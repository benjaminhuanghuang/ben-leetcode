/*
17. Letter Combinations of a Phone Number

https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

/*
    The time complexity is O(4^N x N), N is the length of the input, 4 is count of the letter a digit can map,
    4^N 是组合数量, N is the time to build each combination string.
    The space complexity is also O(4^N * N) because we store all the possible combinations of letters.
    O(N) is the space used by the recursion stack.
*/
function letterCombinations(digits: string): string[] {
  const digitToLettersMap: { [digit: string]: string[] } = {
    "2": ["a", "b", "c"],
    "3": ["d", "e", "f"],
    "4": ["g", "h", "i"],
    "5": ["j", "k", "l"],
    "6": ["m", "n", "o"],
    "7": ["p", "q", "r", "s"],
    "8": ["t", "u", "v"],
    "9": ["w", "x", "y", "z"],
  };

  const lengthOfDigits = digits.length;
  // Base case: if the input string is empty, return an empty list.
  if (lengthOfDigits === 0) {
    return [];
  }
  // List to store the combinations.
  const answer: string[] = [];

  const dfs = (index: number, currentStr: string) => {
    // If the current combination is the same length as the digits string, add to results.
    if (index === lengthOfDigits) {
      answer.push(currentStr);
      return;
    }
    // Loop through the letters mapped to the current digit and recurse for the next digit.
    for (const char of digitToLettersMap[digits[index]]) {
      // Note, use currentStr + char instead of path.append(ch) and path.pop() to avoid mutation
      dfs(index + 1, currentStr + char);
    }
  };

  // Start the recursion with the first digit.
  dfs(0, "");
  // Return the list of generated combinations.
  return answer;
}

function letterCombinations2(digits: string): string[] {
  if (!digits) return [];

  const map: { [key: string]: string } = {
    "2": "abc",
    "3": "def",
    "4": "ghi",
    "5": "jkl",
    "6": "mno",
    "7": "pqrs",
    "8": "tuv",
    "9": "wxyz",
  };

  const res: string[] = [];

  function backtrack(index: number, path: string) {
    if (path.length === digits.length) {
      res.push(path);
      return;
    }

    const letters = map[digits[index]];
    for (const ch of letters) {
      backtrack(index + 1, path + ch);
    }
  }

  backtrack(0, "");
  return res;
}

/*
HuaHua
https://www.youtube.com/watch?v=fLy8t33M1qQ
*/
