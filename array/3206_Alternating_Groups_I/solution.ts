/*
3206. Alternating Groups I

https://leetcode.com/problems/alternating-groups-i/
*/

/*

*/
function numberOfAlternatingGroups(colors: number[]): number {
  let ans = 0;
  const n = colors.length;
  for (let i = 0; i < n; ++i) {
    // check if colors[i], colors[i+1], colors[i+2] are different
    const i2 = (i + 1) % n;
    const i3 = (i + 2) % n;
    if (colors[i] !== colors[i2] && colors[i2] !== colors[i3]) {
      ans++;
    }
  }
  return ans;
}

export {};
