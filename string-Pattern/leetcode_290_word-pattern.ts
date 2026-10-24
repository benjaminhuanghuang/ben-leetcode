/*
290. Word Pattern

https://leetcode.com/problems/word-pattern/

Input: pattern = "abba", s = "dog cat cat dog"

205. Isomorphic Strings
*/

/*
    wordPattern['constructor'] will return the constructor function of the object.
    (word in wordPattern) also has this issue.
*/
function wordPattern_error(pattern: string, s: string): boolean {
  const patternWord: { [key: string]: string } = {};
  const wordPattern: { [key: string]: string } = {};

  const words = s.split(" ");
  if (words.length !== pattern.length) return false;

  for (let i = 0; i < pattern.length; i++) {
    const pChar = pattern[i];
    const word = words[i];

    if (!patternWord[pChar]) {
      patternWord[pChar] = word;
    } else {
      if (patternWord[pChar] !== word) return false;
    }

    if (!wordPattern[word]) {
      wordPattern[word] = pChar;
    } else {
      if (wordPattern[word] !== pChar) return false;
    }
  }
  return true;
}

function wordPattern(pattern: string, s: string): boolean {
  const patternWord: Map<string, string> = new Map();
  const wordPattern: Map<string, string> = new Map();

  const words = s.split(" ");
  if (words.length !== pattern.length) return false;

  for (let i = 0; i < pattern.length; i++) {
    const pChar = pattern[i];
    const word = words[i];

    if (!patternWord.get(pChar)) {
      patternWord.set(pChar, word);
    } else {
      if (patternWord.get(pChar) !== word) return false;
    }

    if (!wordPattern.get(word)) {
      wordPattern.set(word, pChar);
    } else {
      if (wordPattern.get(word) !== pChar) return false;
    }
  }
  return true;
}

export { wordPattern };
