/*
Walk the array comparing arr[i] to arr[i - m]. Count consecutive matches;
a run of m*(k-1) consecutive matches means the length-m pattern ending at
i - m*(k-1) repeats k times in a row. Any mismatch resets the count.

Time complexity: O(n)
Space complexity: O(1)
*/
function containsPattern(arr: number[], m: number, k: number): boolean {
  const need = m * (k - 1);
  let count = 0;

  for (let i = m; i < arr.length; i++) {
    if (arr[i] === arr[i - m]) {
      count++;
      if (count >= need) return true;
    } else {
      count = 0;
    }
  }

  return false;
}

export {};
