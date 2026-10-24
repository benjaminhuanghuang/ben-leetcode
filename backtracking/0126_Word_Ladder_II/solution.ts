/*
126. Word Ladder II

https://leetcode.com/problems/word-ladder-ii/

127. word ladder (BFS)

*/

function findLadders(
  beginWord: string,
  endWord: string,
  wordList: string[]
): string[][] {
  const wordSet: Set<string> = new Set(wordList);
  let res: string[][] = [];
  BFS(beginWord, endWord, [beginWord], wordSet, res);

  res = res.sort((a, b) => a.length - b.length);
  res = res.filter((s) => s.length === res[0].length);
  return res;
}

function BFS(
  currWord: string,
  endWord: string,
  ladder: string[],
  wordSet: Set<string>,
  res: string[][]
): void {
  const nextWords = getNextWords(currWord, wordSet);

  if (nextWords.size === 0) {
    return;
  }

  for (const nextWord of nextWords.keys()) {
    const newLadder = [...ladder, nextWord];
    if (nextWord === endWord) {
      res.push(newLadder);
      return;
    } else {
      BFS(
        nextWord,
        endWord,
        newLadder,
        nextWords.get(nextWord) as Set<string>,
        res
      );
    }
  }
}

function getNextWords(
  word: string,
  wordSet: Set<string>
): Map<string, Set<string>> {
  const nextWords = new Map<string, Set<string>>();

  for (let i = 0; i < word.length; i++) {
    for (let c = 97; c <= 122; c++) {
      // 'a' to 'z'
      if (c !== word.charCodeAt(i)) {
        // replace the i-th character with c
        const charArr = word.split("");
        charArr[i] = String.fromCharCode(c);
        const nextWord = charArr.join("");

        if (wordSet.has(nextWord)) {
          if (!nextWords.has(nextWord)) {
            const newSet = new Set(wordSet);
            newSet.delete(nextWord);
            nextWords.set(nextWord, newSet);
          }
        }
      }
    }
  }

  return nextWords;
}
