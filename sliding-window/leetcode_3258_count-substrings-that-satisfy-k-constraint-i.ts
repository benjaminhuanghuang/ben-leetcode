/*
3258. Count Substrings That Satisfy K-Constraint I


*/

/*
use two variables  cnt0, cnt1
to record the number of 0 and 1 in the current window
*/

function countKConstraintSubstrings(s: string, k: number): number {
  let [cnt0, cnt1, ans, left] = [0, 0, 0, 0];

  for (let r = 0; r < s.length; ++r) {
    const x = s[r] === "1" ? 1 : 0;
    cnt0 += x ^ 1;
    cnt1 += x;
    while (cnt0 > k && cnt1 > k) {
      const y = s[left++] === "1" ? 1 : 0;
      cnt0 -= y ^ 1;
      cnt1 -= y;
    }
    // At this point, all substrings in the window satisfy the
    // constraint, and the number of such substrings is r - left + 1
    ans += r - left + 1;
  }
  return ans;
}
