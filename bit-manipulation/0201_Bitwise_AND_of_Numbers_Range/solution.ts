/*
201. Bitwise AND of Numbers Range

https://leetcode.com/problems/bitwise-and-of-numbers-range/
*/

/*
    The bitwise AND of all numbers in a range is keeping the common bits of m and n from left to right until the first bit that they are different.
    The rest of the bits on the right side are all 0 after the first bit that they are different.
    For example, for number 26 and 30:
    11010
    11011
    11100
    11101
    11110
    11111
    So we are going to keep 11000 from the left side and fill the right side with 0.

    平移m和n，每次向右移一位，直到m和n相等，记录下所有平移的次数i，然后再把m左移i位即为最终结果
*/
function rangeBitwiseAnd(left: number, right: number): number {
  let shift = 0;
  while (left < right) {
    left >>= 1;
    right >>= 1;
    shift++;
  }

  return right << shift;
}
