/*
3208. Alternating Groups II

https://leetcode.com/problems/alternating-groups-ii/

- 3206. Alternating Groups I
*/

/*
We can unfold the ring into an array of length 2n and then traverse this array from left to right. 
We
use a variable ent to record the current length of the alternating group. 
If we encounter the same color, we reset cnt to 1; otherwise cnt++. 
*/
function numberOfAlternatingGroups(colors: number[], k: number): number {
  const n = colors.length;
  let [ans, cnt] = [0, 1];
  for (let i = 0; i < n + k - 2; ++i) {
    if (colors[i % n] === colors[(i + 1) % n]) {
      cnt = 1;
    } else {
      ++cnt;
    }
    if (cnt >= k) {
      ans += 1;
    }
  }
  return ans;
}
