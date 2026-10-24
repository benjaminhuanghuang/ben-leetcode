/*
Find the index of the gas station you would need to start at,

关键贪心逻辑：从任何在 start 到 i 之间的站出发，也无法到达 i+1，所以只能把 start 移到 i+1。
*/
function gas_stations(gas: number[], cost: number[]): number {
  // If total gas is less than total cost, completing the circuit is impossible
  if (gas.reduce((a, b) => a + b, 0) < cost.reduce((a, b) => a + b, 0)) {
    return -1;
  }

  let start = 0; // The starting gas station index
  let tank = 0; // Current fuel in tank

  for (let i = 0; i < gas.length; i++) {
    // 从当前加油站走到下一个加油站后，油箱剩余多少油。
    tank += gas[i] - cost[i];

    // If tank becomes negative, we can't reach station i+1 from current start
    if (tank < 0) {
      // Choose next station as new starting point
      start = i + 1;
      tank = 0; // Reset tank
    }
  }

  return start;
}

/*
Time complexity: The time complexity of gas_stations is O(n), where n denotes the length of
the input arrays. This is because we iterate through each element in the gas and cost arrays.

Space complexity: The space complexity is O(1).
*/
