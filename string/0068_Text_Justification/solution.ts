/*
68. Text Justification

https://leetcode.com/problems/text-justification/
*/

/*
  单词排成行, 尽量均匀插入空格，最后用空格填充
 */
function fullJustify(words: string[], maxWidth: number): string[] {
  const res: string[] = [];
  let wordIdx = 0;

  while (wordIdx < words.length) {
    let charCount = words[wordIdx].length;
    let lastWordIdx = wordIdx + 1; // index of the last word in the line, exclusive

    // try to put as many words as possible in the line
    while (lastWordIdx < words.length) {
      if (words[lastWordIdx].length + charCount + 1 > maxWidth)
        // + 1 is the space
        break;
      charCount += 1 + words[lastWordIdx].length;
      lastWordIdx++;
    }

    let textLine = words[wordIdx];
    let spaces = lastWordIdx - wordIdx - 1; // number of gaps between words in line

    if (lastWordIdx === words.length || spaces === 0) {
      // if it is the last line or there is only one word in the line
      for (let i = wordIdx + 1; i < lastWordIdx; i++) {
        textLine += " ";
        textLine += words[i];
      }
      while (textLine.length < maxWidth) {
        textLine += " ";
      }
    } else {
      let spacesBetweenWords = Math.floor((maxWidth - charCount) / spaces);
      /*
            If the number of spaces on a line do not divide evenly between words, the empty slots on the left will
            be assigned more spaces than the slots on the right.
            */
      let spacesRemainder = (maxWidth - charCount) % spaces;

      for (let i = wordIdx + 1; i < lastWordIdx; i++) {
        // those spaces are padding spaces between words
        textLine += " ".repeat(spacesBetweenWords);
        if (spacesRemainder > 0) {
          textLine += " ";
          spacesRemainder--;
        }
        // this space is single space between words for general case
        textLine += " ";
        textLine += words[i];
      }
    }
    res.push(textLine);
    wordIdx = lastWordIdx;
  }

  return res;
}

export { fullJustify };
