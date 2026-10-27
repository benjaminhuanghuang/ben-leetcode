/*
https://leetcode.com/problems/string-compression/

双指针原地压缩：read 扫描原数组，write 写压缩结果
每组相同字符：写字符本身，若连续个数 > 1 再写个数（按位拆成多个字符）
*/
function compress(chars: string[]): number {
  let write = 0;
  let read = 0;

  while (read < chars.length) {
    const char = chars[read];
    let count = 0;
    while (read < chars.length && chars[read] === char) {
      read++;
      count++;
    }

    chars[write++] = char;
    if (count > 1) {
      for (const digit of String(count)) {
        chars[write++] = digit;
      }
    }
  }

  return write;
}

export {};
