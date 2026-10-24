/*
720. Longest Word in Dictionary

https://leetcode.com/problems/longest-word-in-dictionary/

[Google]
*/

/*
    HuaHua
    https://www.youtube.com/watch?v=TqrZg4wYP1U

    Bruteforce: 
    check one word, the time complexity is O(n), (length of word)^2 
    The total time complexity is Sum of time of all words = Sum of (length of word)^2
    对于每一个word，通过哈希表检查是否所有的前缀都在set当中需要O(w_i^2)。

    Space complexity: O(n * w)
*/

/*
    HuaHua
    https://www.youtube.com/watch?v=TqrZg4wYP1U

    Trie: 
    Check the prefix of every word, the time complexity is O(1) * (length of word) = (length of word)
    The total time complexity is Sum of time of all words = Sum of (length of word)

    Space complexity: O(26 * n * w)
*/

import { Trie } from "./Trie";

function longestWord_Trie(words: string[]): string {
  // Sort words in descending order, longer words come first
  words.sort((a, b) => {
    // Compare by length first (descending), longer words come first
    if (a.length !== b.length) {
      return b.length - a.length;
    }
    // If lengths are the same, compare alphabetically
    return a.localeCompare(b);
  });

  const trie = new Trie();
  for (const word of words) {
    trie.insert(word);
  }
  for (const word of words) {
    if (trie.hasAllPrefixes(word)) {
      return word;
    }
  }
  return "";
}
