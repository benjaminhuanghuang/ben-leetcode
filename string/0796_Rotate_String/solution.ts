/*
https://leetcode.com/problems/rotate-string/

s 经过若干次旋转能变成 goal，等价于：长度相等 且 goal 是 s+s 的子串
*/
function rotateString(s: string, goal: string): boolean {
  if (s.length !== goal.length) return false;
  return (s + s).includes(goal);
}

export {};
