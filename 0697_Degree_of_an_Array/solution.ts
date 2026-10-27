/*
https://leetcode.com/problems/degree-of-an-array/

degree = 数组中出现次数最多的元素的出现次数
找到一个连续子数组，使它和原数组有相同的最高元素出现频率，并且这个子数组尽可能短。

对每个数字记录第一次出现下标、最后一次出现下标、出现次数
答案取出现次数等于 degree 的数字中 (lastIndex - firstIndex + 1) 的最小值
*/
function findShortestSubArray(nums: number[]): number {
  const first = new Map<number, number>();
  const count = new Map<number, number>();
  let degree = 0;
  let result = 0;

  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];
    if (!first.has(num)) {
      first.set(num, i);
    }
    const c = (count.get(num) ?? 0) + 1;
    count.set(num, c);

    if (c > degree) {
      degree = c;
      result = i - first.get(num)! + 1;
    } else if (c === degree) {
      result = Math.min(result, i - first.get(num)! + 1);
    }
  }

  return result;
}

export {};
