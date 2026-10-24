/*
13. Roman to Integer

https://leetcode.com/problems/roman-to-integer/


To "VII", we use the [additive notation], 'V' + 'I' + 'I' = 5 + 1 + 1 = 7.
To "IV" we use the [subtractive  notation]. 'V' - 'I' = 5 - 1 = 4.

*/

/*
  current < next => - current,
  current >= next => + current,
  "IV"→ -1+5，"VI"→ 5+1
*/
function romanToInt(s: string): number {
  const romanToIntMap: { [key: string]: number } = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
  };

  let total = 0;
  for (let i = 0; i < s.length; i++) {
    const cur = romanToIntMap[s[i]];
    const hasNext = i + 1 < s.length;
    if (hasNext && romanToIntMap[s[i + 1]] > cur) {
      total -= cur;
    } else {
      total += cur;
    }
  }
  return total;
}

function romanToInt2(s: string): number {
  const romanToIntMap: { [key: string]: number } = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
  };

  let result = 0;
  let prevValue = 0;
  // from lowest bit to highest bit
  for (let i = s.length - 1; i >= 0; i--) {
    const curr = romanToIntMap[s[i]];
    if (curr < prevValue) {
      result -= curr;
    } else {
      result += curr;
    }
    prevValue = curr;
  }
  return result;
}
