import { wordPattern } from "./leetcode_290_word-pattern";

describe("Check if the pattern matches the string", () => {
  it('should return true for pattern = "abba", s = "dog constructor constructor dog"', () => {
    expect(wordPattern("abba", "dog constructor constructor dog")).toBe(true);
  });
});
