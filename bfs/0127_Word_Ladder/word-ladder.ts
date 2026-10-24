/*

Word Ladder


Talk-through: BFS where each transformation is one edge. Instead of building
an explicit graph, generate neighbors on the fly: for each position in the
word, try all 26 letters and check membership in the word set. BFS
guarantees the first time endWord is reached is via the shortest path.
Remove words from the set once visited so they aren't reprocessed.

Time big O of n * L * 26 where n is word count and L is word length, space
big O of n.
*/
function ladderLength(
  beginWord: string,
  endWord: string,
  wordList: string[]
): number {
  const wordSet = new Set(wordList);
  if (!wordSet.has(endWord)) return 0;

  const queue: [string, number][] = [[beginWord, 1]];
  wordSet.delete(beginWord);

  while (queue.length > 0) {
    const [word, steps] = queue.shift()!;
    if (word === endWord) return steps;

    for (let i = 0; i < word.length; i++) {
      for (let code = 97; code <= 122; code++) {
        const candidate =
          word.slice(0, i) + String.fromCharCode(code) + word.slice(i + 1);

        if (wordSet.has(candidate)) {
          wordSet.delete(candidate);
          queue.push([candidate, steps + 1]);
        }
      }
    }
  }

  return 0;
}
