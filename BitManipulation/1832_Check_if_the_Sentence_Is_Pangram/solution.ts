/*
1832. Check if the Sentence Is Pangram

https://leetcode.com/problems/check-if-the-sentence-is-pangram/
*/

function checkIfPangram(sentence: string): boolean {
  // Each bit of 'mark' represents one letter of the alphabet
  let mark = 0;

  for (const char of sentence) {
    const alphabetIndex = char.charCodeAt(0) - "a".charCodeAt(0);
    mark |= 1 << alphabetIndex;
  }

  // Check if all 26 bits are set to 1
  // (1 << 26) creates a number with 26 0s followed by a 1
  // Subtracting 1 from that number flips all 26 0s to 1s
  // Comparing 'mark' to this value verifies if all letters of the alphabet are present
  return mark === (1 << 26) - 1;
}

function sortSentence(s: string): string {
  let arr = s.split(" ");
  const arr2: [string, string][] = arr.map((w) => {
    return [w.slice(0, w.length), w.slice(w.length - 1)];
  });
  arr2.sort((a, b) => Number(a[1]) - Number(b[1]));
  return arr2.map((w) => w[0]).join(" ");
}
