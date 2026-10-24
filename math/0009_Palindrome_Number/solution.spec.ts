import { isPalindrome } from "./leetcode_9_palindrome-number";

describe("isPalindrome", () => {
  it("Example test cases", () => {
    expect(isPalindrome(121)).toBe(true);
    expect(isPalindrome(-121)).toBe(false);
    expect(isPalindrome(10)).toBe(false);
    expect(isPalindrome(-101)).toBe(false);
  });
});
