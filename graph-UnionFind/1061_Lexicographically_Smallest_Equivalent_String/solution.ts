/*
1061. Lexicographically Smallest Equivalent String

https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

Reflexivity: 'a' == 'a'.
Symmetry: 'a' == 'b' implies 'b' == 'a'.
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
*/

/*
https://www.youtube.com/watch?v=SYLbXrror_k (HuaHua)

Graph

等价的字符会形成一个连通分量
Use the smallest letter in a connected component as the root

*/

function smallestEquivalentString(
  s1: string,
  s2: string,
  baseStr: string
): string {
  // point i to it self
  let p: number[] = new Array(26).fill(0).map((_, i) => i);

  const find = (x: number): number => {
    return p[x] === x ? x : (p[x] = find(p[x]));
  };

  for (let i = 0; i < s1.length; ++i) {
    let r1 = find(s1.charCodeAt(i) - "a".charCodeAt(0));
    let r2 = find(s2.charCodeAt(i) - "a".charCodeAt(0));
    if (r2 < r1) [r1, r2] = [r2, r1]; // make sure r1 is the smallest
    p[r2] = r1;
  }

  // convert the index to letter
  let ans: string = baseStr
    .split("")
    .map((char) => {
      return String.fromCharCode(
        find(char.charCodeAt(0) - "a".charCodeAt(0)) + "a".charCodeAt(0)
      );
    })
    .join("");

  return ans;
}
