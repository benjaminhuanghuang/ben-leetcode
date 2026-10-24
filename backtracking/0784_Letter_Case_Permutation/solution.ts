/*
784. Letter Case Permutation

https://leetcode.com/problems/letter-case-permutation/
*/

/*
  http://zxi.mytechroad.com/blog/searching/leetcode-784-letter-case-permutation/
*/
function letterCasePermutation(s: string): string[] {
  const ans: string[] = [];

  dfs(s.split(""), 0, ans);

  return ans;
}

function dfs(charArr: string[], index: number, ans: string[]): void {
  if (index === charArr.length) {
    ans.push(charArr.join(""));
    return;
  }

  dfs(charArr, index + 1, ans);

  if (!isNaN(Number(charArr[index]))) return;

  charArr[index] = String.fromCharCode(charArr[index].charCodeAt(0) ^ (1 << 5));

  dfs(charArr, index + 1, ans);
  // Backtrack
  charArr[index] = String.fromCharCode(charArr[index].charCodeAt(0) ^ (1 << 5));
}
