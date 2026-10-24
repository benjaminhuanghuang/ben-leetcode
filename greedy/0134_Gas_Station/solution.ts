/*
134. Gas Station

https://leetcode.com/problems/gas-station/
*/

/*
    gas     1  2  3  4  5
    cost    3  4  5  1  2
    gasLeft -2 -2 -2 3  3
    The goal is to find the start point that can make the sum of gasLeft >= 0

    when we check gas left(start from x, end y), 
    if gas left < 0, we can make sure that it could not 
    start from any point between x and y. and the potential start point would be y + 1, and 
    reset the gas left to 0;
    */
function canCompleteCircuit(gas: number[], cost: number[]): number {
  var gasLeft = 0;
  var total = 0;
  var start = 0;
  for (let i = 0; i < gas.length; i++) {
    gasLeft += gas[i] - cost[i];
    if (gasLeft < 0) {
      start = i + 1;
      total += gasLeft; // sum(gas) - sum(cost)
      gasLeft = 0;
    }
  }
  // total + gasLeft is sum(gas) - sum(cost)
  //reduce the 2 times traversal to just 1 time.
  return total + gasLeft < 0 ? -1 : start;
}

// start point and end point in 0,
// if sum >= 0 move end point,
// if sum < 0, move start point backward until sum >= 0.
function canCompleteCircuit_2(gas: number[], cost: number[]): number {
  let len = gas.length;
  let start = 0;
  var end = 0;
  let sum = 0;

  while (true) {
    sum += gas[end] - cost[end];
    end = (end + 1) % len;
    while (sum < 0) {
      if (start == end) break;
      start = (start - 1 + len) % len;
      sum += gas[start] - cost[start];
    }
    if (start == end) {
      if (sum >= 0) return start;
      return -1;
    }
  }
}
