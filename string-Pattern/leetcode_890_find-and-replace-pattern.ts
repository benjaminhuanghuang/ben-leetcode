/*
890. Find and Replace Pattern

https://leetcode.com/problems/find-and-replace-pattern/
*/

function findAndReplacePattern(words: string[], pattern: string): string[] {
  return words.filter((word) => {
    const wordToPatternMap = new Map<string, number>();
    const patternToWordMap = new Map<string, number>();

    for (let i = 0; i < word.length; i++) {
      // Check if there is a mismatch between the current mappings of the word and pattern
      if (wordToPatternMap.get(word[i]) !== patternToWordMap.get(pattern[i])) {
        return false;
      }
      // Update the mappings with the current index
      wordToPatternMap.set(word[i], i);
      patternToWordMap.set(pattern[i], i);
    }
    return true;
  });
}
