/*
93. Restore IP Addresses

https://leetcode.com/problems/restore-ip-addresses/

给定一个只包含数字的字符串 s，返回所有可能的 有效 IP 地址。

*/
/*
    https://www.youtube.com/watch?v=pi-S2TLYuL4

    time: O(3^4)=>O(1)  space: O(n)
*/
function restoreIpAddresses(s: string): string[] {
  const ans: string[] = [];
  const curr: string = "";
  dfs(s, 0, 0, curr, ans);
  return ans;
}

function dfs(
  s: string,
  count: number,
  start: number,
  curr: string,
  ans: string[]
): void {
  // 超过 4 段，pruning
  if (count > 4) {
    return;
  }
  // 正好 4 段，并且用完所有字符
  if (count === 4 && start === s.length) {
    ans.push(curr);
    return;
  }

  for (let i = 1; i < 4; i++) {
    // Take 1, 2, or 3 digits
    if (start + i > s.length) break;

    const tmp = s.substring(start, start + i);
    if ((tmp[0] === "0" && tmp.length > 1) || (i === 3 && parseInt(tmp) >= 256))
      continue;

    dfs(s, count + 1, start + i, curr + tmp + (count === 3 ? "" : "."), ans);
  }
}
