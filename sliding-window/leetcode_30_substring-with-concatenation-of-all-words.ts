/*
30. Substring with Concatenation of All Words

https://leetcode.com/problems/substring-with-concatenation-of-all-words/

Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

convert the question to:
Find substring, which contains all words in the list, and the order of words doesn't matter.
The length of the substring = words.length * word.length

*/

/*

https://algo.monster/liteproblems/30

Time complexity:  O(m * k) where m is the length of the string s and k is the length of each word within the words list

*/
function findSubstring(s: string, words: string[]): number[] {
  // Create a map to store the frequency of words.
  const wordCountMap: Map<string, number> = new Map();
  // Populate the word frequency map.
  for (const word of words) {
    wordCountMap.set(word, (wordCountMap.get(word) || 0) + 1);
  }

  const stringLength: number = s.length;
  const wordArrayLength: number = words.length;
  const wordLength: number = words[0].length;
  const indices: number[] = [];

  // The sliding window starts from the beginning of s, and we move it to the right one word-length at a time.
  // We continue this process for all possible positions the first word of the window could start from (i.e., 0 to word-length - 1).

  // At each step, when a new word is included in the sliding window:
  // - We add it to a current word frequency count hash table.
  // - If this new word isn't in the original words count hash table, we reset the current one, as it's not a valid continuation.
  // - If the count of the newly added word exceeds its expected count, we slide the window's left bound to the right to exclude enough occurrences, so the counts match.
  // - Whenever the number of words within the sliding window is equal to the size of words and all word counts correspond, we record the starting index.
  for (let i = 0; i < wordLength; ++i) {
    const tempCountMap: Map<string, number> = new Map(); // count the frequency of words in the current sliding window
    let left = i;
    let right = i;
    let matchedWordCount = 0;

    // Scan the string in chunks the size of the words' length
    while (right + wordLength <= stringLength) {
      const currentWord = s.slice(right, right + wordLength);
      right += wordLength;

      // Skip the word if it's not in the frequency map
      if (!wordCountMap.has(currentWord)) {
        tempCountMap.clear();
        left = right;
        matchedWordCount = 0;
        continue;
      }

      // Update the temporary count map
      tempCountMap.set(currentWord, (tempCountMap.get(currentWord) || 0) + 1);
      ++matchedWordCount;

      // If the current word has been seen more times than it is present in words array, slide the window to the right
      while (
        tempCountMap.get(currentWord)! - wordCountMap.get(currentWord)! >
        0
      ) {
        const wordToLeft = s.slice(left, left + wordLength);
        tempCountMap.set(wordToLeft, tempCountMap.get(wordToLeft)! - 1);
        left += wordLength;
        --matchedWordCount;
      }

      // Check if all words match; if so, add to results
      if (matchedWordCount === wordArrayLength) {
        indices.push(left);
      }
    }
  }

  return indices;
}

/*
Hua Hua
https://zxi.mytechroad.com/blog/hashtable/leetcode-30-substring-with-concatenation-of-all-words/

Solution1: HashTable + Brute Force
S is length of string
W is length of word list

Time complexity: O((|S| – |W|*l) * |W|*l))
Space complexity: O(|W|*l)
*/
