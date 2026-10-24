/*
459. Repeated Substring Pattern

https://leetcode.com/problems/repeated-substring-pattern/

[Google]
*/
function repeatedSubstringPattern(s: string): boolean {
  const n = s.length;

  for (let len = Math.floor(n / 2); len >= 1; --len) {
    if (n % len === 0) {
      const count = Math.floor(n / len);
      /*
            为什么用从0开始的len个字符重复count次？因为如果s必须包含从0开始的字符
            */
      const t = s.substring(0, len).repeat(count);
      if (t === s) {
        return true;
      }
    }
  }
  return false;
}
/*
    https://www.youtube.com/watch?v=9qH-M4SKpj0
    Approach : KMP
    判断一个string是否由一个子串重复多次构成。
    在s+s中，去掉第一个和最后一个字符，如果s还在s+s中，那么s就是由一个子串重复多次构成的。


    设t = s + s，若s在t中的起始位置不为0或n，则符合条件，
    那么设这个起始位置为i (0<i<n),s[x:y]表示s的第x个字符到第y个字符
    s[0: n - 1] = t[i: n + i - 1]
    将t[i: n + i - 1]在n - 1位置分成两段
    s[0: n - i - 1] = t[i: n - 1]
    s[n - i: n - 1] = t[n: n + i - 1] = t[0: i - 1]

    s[0: n - i - 1] = s[i: n - 1]
    s[n - i: n - 1] = s[0: i - 1]
    对于任意j，s[j % n] = s[(j + i) % n]
*/
function repeatedSubstringPattern2(s: string): boolean {
  return (s + s).substring(1, s.length * 2 - 1).includes(s);
}
