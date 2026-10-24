/*
    next_permutation
        找 pivot（从右向左第一个下降点）
        找 pivot 右边最小的比 pivot 大的字符（继任者）
        交换 pivot 和继任者
        反转 pivot 右边的后缀
        返回新的字符串
    Time Complexity: O(N) where N is the length of the input string.
    Space Complexity: O(N) for the array used to store characters.
*/

export function nextLexicographicalSequence(s: string): string {
  let letters: string[] = [...s];
  // Locate the pivot, which is the first character from the right that breaks
  // non-increasing order. Start searching from the second-to-last position.
  let pivot = letters.length - 2;
  while (pivot >= 0 && letters[pivot] >= letters[pivot + 1]) pivot--;
  // If pivot is not found, the string is already in its largest permutation. In
  // this case, reverse the string to obtain the smallest permutation.
  if (pivot === -1) return letters.reverse().join("");
  // Find the rightmost successor to the pivot.
  let rightmostSuccessor = letters.length - 1;
  while (letters[rightmostSuccessor] <= letters[pivot]) rightmostSuccessor--;
  // Swap the rightmost successor with the pivot to increase the lexicographical
  // order of the suffix.
  [letters[pivot], letters[rightmostSuccessor]] = [
    letters[rightmostSuccessor],
    letters[pivot],
  ];
  // Reverse the suffix after the pivot to minimize its permutation.
  const suffix = letters.slice(pivot + 1).reverse();
  letters.splice(pivot + 1, suffix.length, ...suffix);
  return letters.join("");
}
