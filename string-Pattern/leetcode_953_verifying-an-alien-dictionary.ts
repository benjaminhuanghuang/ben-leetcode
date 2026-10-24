/*
953. Verifying an Alien Dictionary

https://leetcode.com/problems/verifying-an-alien-dictionary/
*/

/*
  https://zxi.mytechroad.com/blog/hashtable/leetcode-953-verifying-an-alien-dictionary/
    Time complexity: O(sum(len(words[i])))

    Space complexity: O(26)
    transform each word to the new language order
*/
function isAlienSorted2(words: string[], order: string): boolean {
  const m: string[] = new Array(26);

  for (let i = 0; i < 26; ++i) {
    m[order.charCodeAt(i) - 97] = String.fromCharCode(97 + i);
  }

  for (let i = 0; i < words.length; ++i) {
    let transformedWord = "";

    for (let j = 0; j < words[i].length; ++j) {
      transformedWord += m[words[i].charCodeAt(j) - 97];
    }

    words[i] = transformedWord;

    if (i > 0 && words[i] < words[i - 1]) {
      return false;
    }
  }

  return true;
}

function isAlienSorted(words: string[], order: string): boolean {
  // Create a mapping of each character to its position in the new language order
  const charPositionMap = new Map<string, number>();
  for (const char of order) {
    charPositionMap.set(char, charPositionMap.size); // map char to it's index
  }

  // Iterate through the pairs of adjacent words
  for (let i = 1; i < words.length; i++) {
    const firstWord = words[i - 1];
    const secondWord = words[i];

    // Find the minimum length to compare both words
    const minLength = Math.min(firstWord.length, secondWord.length);
    let areWordsEqual = false;

    // Compare characters of both words
    for (let j = 0; j < minLength; j++) {
      if (
        charPositionMap.get(firstWord[j])! > charPositionMap.get(secondWord[j])!
      ) {
        // The first word is greater than the second, so the list is not sorted
        return false;
      }
      if (
        charPositionMap.get(firstWord[j])! < charPositionMap.get(secondWord[j])!
      ) {
        // The first word comes before the second, so we can break the comparison
        areWordsEqual = true;
        break;
      }
    }

    // If all characters are equal, but the length of the first word is greater, the list is not sorted
    if (!areWordsEqual && firstWord.length > secondWord.length) {
      return false;
    }
  }

  // If all words are properly sorted or equal, return true
  return true;
}
