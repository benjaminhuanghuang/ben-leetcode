/*
Q: Given a string S, return the length of the longest palindromic substring within S.
*/
/*
中心扩展法（Center Expansion），优点是实现简单，空间开销小；缺点是最坏情况下时间复杂度是 O(n²)。
 Time: O(n^2), Space: O(n)
*/
function longest(s: string): number {
  let length = 0;

  // 遍历字符串的每一个字符，i 被当作 回文的中心点
  for (let i = 0; i < s.length; i++) {
    // Odd length
    let l = i,
      r = i;
    while (l >= 0 && r < s.length && s[l] === s[r]) {
      if (r - l + 1 > length) {
        // update max length
        length = r - l + 1;
      }
      l--;
      r++;
    }

    // Even length
    l = i;
    r = i + 1;
    while (l >= 0 && r < s.length && s[l] === s[r]) {
      if (r - l + 1 > length) {
        // update max length
        length = r - l + 1;
      }
      l--;
      r++;
    }
  }

  return length;
}
