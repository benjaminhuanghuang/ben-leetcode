import { isPalindrome_Inplace as isPalindrome } from "./leetcode_125_valid-palindrome";

describe("isPalindrome", () => {
  test("Example 1", () => {
    const input = "race a car";
    expect(isPalindrome(input)).toBeFalsy();
  });

  test("Example 2", () => {
    const input = "A man, a plan, a canal: Panama";
    expect(isPalindrome(input)).toBeTruthy();
  });
});
