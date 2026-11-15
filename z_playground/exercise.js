/**
 * @param {string} digits
 * @return {string[]}
 */
function letterCombinations(digits) {
  // TODO: implement
  if (digits.length == 0) return [];
  const charMap = new Map([
    ["2", "abc"],
    ["3", "def"],
    ["4", "ghi"],
    ["5", "jkl"],
    ["6", "mno"],
    ["7", "pqrs"],
    ["8", "tuv"],
    ["9", "wxyz"],
  ]);

  const ans = [];
  const dfs = (i, candidate) => {
    if (i === digits.length) {
      ans.push(candidate);
      return;
    }

    for (const c of charMap.get(digits[i])) {
      dfs(i + 1, candidate + c);
    }
  };

  dfs(0, "");

  return ans;
}
