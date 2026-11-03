/*
  I use DP with a Hash Map where the key is the stone position, and the value is a Set of jump sizes that can reach this stone.

  For each stone, look at all valid jump sizes k. The frog can jump k - 1, k, or k + 1 units forward. 
  If stone + step exists in our stone map, add step to that stone's set.
  Start at stone 0 with jump 0. Also, if stones[1] !== 1, return false immediately because the first jump must be 1
  
  At the end, if the last stone has at least one jump in its set, return true.
*/

/**
 * @param {number[]} stones
 * @return {boolean}
 */
var canCross = function (stones) {
  const n = stones.length;

  // Early exit: first jump must reach stone 1 with distance 1
  if (stones[1] !== 1) return false;
  // dp map: stone position -> Set of incoming jump sizes (k)
  const dp = new Map();
  for (const stone of stones) {
    dp.set(stone, new Set());
  }
  // Base case: at stone 0 with jump size 0
  dp.get(0).add(0);
  for (const stone of stones) {
    const jumps = dp.get(stone);
    for (const k of jumps) {
      // Possible next jump sizes: k - 1, k, k + 1
      for (const step of [k - 1, k, k + 1]) {
        if (step > 0 && dp.has(stone + step)) {
          dp.get(stone + step).add(step);
        }
      }
    }
  }
  // If the last stone received any jump, we can cross
  return dp.get(stones[n - 1]).size > 0;
};

export { canCross };
