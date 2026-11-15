/*
Time complexity: O(allowed.length + sum of words[i].length)
Space complexity: O(allowed.length)
*/
function countConsistentStrings(allowed: string, words: string[]): number {
  const allowedSet = new Set(allowed);
  let count = 0;

  for (const word of words) {
    if ([...word].every((ch) => allowedSet.has(ch))) count++;
  }

  return count;
}

export {};
