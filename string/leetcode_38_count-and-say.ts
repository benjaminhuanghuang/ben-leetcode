/*
38. Count and Say

https://leetcode.com/problems/count-and-say/
*/

function countAndSay(n: number): string {
  let ans: string = "1";
  for (let i = 1; i < n; ++i) {
    ans = say(ans);
  }
  return ans;
}

function say(num: string): string {
  let ans: string = "";
  let start: number = 0;
  const len: number = num.length;

  for (let end = 1; end <= len; ++end) {
    if (end === len || num[start] !== num[end]) {
      const count = end - start; // count the same digits
      ans += count.toString(); // Convert count from number to string
      ans += num[start];
      start = end;
    }
  }

  return ans;
}
