/*
151. Reverse Words in a String

https://leetcode.com/problems/reverse-words-in-a-string/
*/

function reverseWords(s: string): string {
  return s
    .split(" ")
    .filter((w) => w === "")
    .reverse()
    .join(" ");
}

function reverseWords2(s: string): string {
  let result = "";
  let wordEnd = s.length - 1;

  for (let i = s.length - 1; i >= 0; i--) {
    if (s[i] === " ") {
      wordEnd = i - 1; // the word ends with ' '
    } else if (i === 0 || s[i - 1] === " ") {
      // word ends with ' ' or the first word
      if (result.length > 0) {
        result += " ";
      }
      result += s.substring(i, wordEnd + 1);
    }
  }

  return result;
}
