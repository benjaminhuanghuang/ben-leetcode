/*
125. Valid Palindrome
https://leetcode.com/problems/valid-palindrome/
*/
function isPalindrome(s: string): boolean {
  s = s.replace(/[^a-zA-Z0-9]/g, "").toLowerCase();

  let left = 0;
  let right = s.length - 1;
  while (left < right) {
    if (s[left] !== s[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

function isAlphanumeric_regex(str: string) {
  return /[a-zA-Z]/.test(str) || /[0-9]/.test(str);
}
function isAlphanumeric(str: string) {
  return (
    (str >= "a" && str <= "z") ||
    (str >= "A" && str <= "Z") ||
    (str >= "0" && str <= "9")
  );
}

function isPalindrome_Inplace(s: string): boolean {
  if (s == null || s.length == 0) {
    return true;
  }

  let left = 0;
  let right = s.length - 1;
  while (left < right) {
    while (left < right && !isAlphanumeric(s[left])) {
      left++;
    }
    while (right > left && !isAlphanumeric(s[right])) {
      right--;
    }

    if (left >= right) {
      return true;
    }

    if (s[left].toLowerCase() != s[right].toLowerCase()) {
      return false;
    }

    left++;
    right--;
  }

  return true;
}

export { isPalindrome_Inplace };
