/*
Time complexity O(n x 22)

*/
const MOD = 1_000_000_007;

function countPairs(deliciousness: number[]): number {
  // deliciousness[i] <= 2^20, so any pair sum is < 2^22
  const maxSum = 1 << 22;
  const count = new Map<number, number>();
  let pairs = 0;

  for (const num of deliciousness) {
    for (let sum = 1; sum <= maxSum; sum <<= 1) {
      const complement = sum - num;
      const seen = count.get(complement);
      if (seen) pairs = (pairs + seen) % MOD;
    }
    count.set(num, (count.get(num) ?? 0) + 1);
  }

  return pairs;
}

export {};
