/*
1441. Build an Array With Stack Operations

https://leetcode.com/problems/build-an-array-with-stack-operations/
*/

function buildArray(target: number[], n: number): string[] {
  const operations = [];
  let currentNumber = 0;

  for (const targetNumber of target) {
    // Increment current number and append 'Push' and 'Pop' until it matches the target number
    while (++currentNumber < targetNumber) {
      // skip the numbers.
      operations.push("Push"); // Simulate pushing the next number onto the stack
      operations.push("Pop"); // Immediately remove it as it's not in the target
    }
    // When current number matches the target number, just perform the 'Push' operation
    operations.push("Push");
  }
  return operations;
}
