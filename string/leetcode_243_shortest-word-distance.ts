/*
243. Shortest Word Distance

https://leetcode.com/problems/shortest-word-distance/
*/
/*
两个单词之间的距离是列表中它们之间的单词数
*/
function shortestDistance(
  wordsDict: string[],
  word1: string,
  word2: string
): number {
  // Initialize shortest distance with the maximum possible value
  let shortestDistance: number = Number.MAX_SAFE_INTEGER;
  // Use indices word1Index and word2Index to keep track of the most recent positions of word1 and word2
  // Initialize both indices to -1, indicating that these words have not been encountered yet
  let word1Index: number = -1;
  let word2Index: number = -1;

  // Loop through all words in the dictionary
  for (let k = 0; k < wordsDict.length; ++k) {
    if (wordsDict[k] === word1) {
      // If the current word is word1
      word1Index = k; // Update index of word1
    }
    if (wordsDict[k] === word2) {
      // If the current word is word2
      word2Index = k; // Update index of word2
    }

    // If both words have been seen at least once
    if (word1Index !== -1 && word2Index !== -1) {
      // Calculate the distance and update shortestDistance if it's smaller
      shortestDistance = Math.min(
        shortestDistance,
        Math.abs(word1Index - word2Index)
      );
    }
  }

  // Return the shortest distance found
  return shortestDistance;
}
