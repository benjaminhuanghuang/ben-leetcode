/*
127. word ladder
https://leetcode.com/problems/word-ladder/
*/

/*
  典型的 BFS问题：

  节点：一个单词
  边：两个单词如果只差一个字符，则可相互转换

  目标：从 beginWord 变到 endWord，找最短转换序列长度


  Time complexity - 0(n*25^l) - l as length of word; n as wordlist length
  Space complexity - 0(N) - N as wordlist length
*/
function ladderLength(
  beginWord: string,
  endWord: string,
  wordList: string[]
): number {
  const words = new Set<string>(wordList); // remove the duplicate words
  if (!words.has(endWord)) return 0; // If the end word is not in the set, no transformation sequence exists.
  if (words.has(beginWord)) words.delete(beginWord); // Remove the begin word from the set (if it exists

  // BFS
  const queue: string[] = [beginWord];
  const visited = new Set<string>([beginWord]);
  let level = 1;
  while (queue.length > 0) {
    const size = queue.length;
    for (let i = 0; i < size; i++) {
      const word = queue.shift()!;
      if (word === endWord) return level;
      for (let j = 0; j < word.length; j++) {
        for (let k = 0; k < 26; k++) {
          const newWord = replaceAt(word, j, String.fromCharCode(97 + k));
          if (words.has(newWord) && !visited.has(newWord)) {
            queue.push(newWord);
            visited.add(newWord);
          }
        }
      }
    }
    level++;
  }
  return 0;
}

// Replace character at specific index in a string
function replaceAt(str: string, index: number, character: string): string {
  if (index < 0 || index >= str.length) {
    throw new Error("Index out of bounds");
  }
  return str.substring(0, index) + character + str.substring(index + 1);
}
