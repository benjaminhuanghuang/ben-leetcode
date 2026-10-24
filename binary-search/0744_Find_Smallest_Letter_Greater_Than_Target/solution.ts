/*
744. Find Smallest Letter Greater Than Target

https://leetcode.com/problems/find-smallest-letter-greater-than-target/
*/
function nextGreatestLetter(letters: string[], target: string): string {
  let left = 0;
  let right = letters.length;

  while (left < right) {
    let mid = left + Math.floor((right - left) / 2);
    if (letters[mid] > target) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return letters[left % letters.length];
}
