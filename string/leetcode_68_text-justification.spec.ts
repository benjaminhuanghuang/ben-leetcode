import { fullJustify } from "./leetcode_68_text-justification";

describe("Text Justification", () => {
  it("Test 1", () => {
    const words = [
      "This",
      "is",
      "an",
      "example",
      "of",
      "text",
      "justification.",
    ];
    const maxWidth = 16;
    const expected = [
      "This    is    an",
      "example  of text",
      "justification.  ",
    ];
    const result = fullJustify(words, maxWidth);
    expect(result).toEqual(expected);
  });
});
