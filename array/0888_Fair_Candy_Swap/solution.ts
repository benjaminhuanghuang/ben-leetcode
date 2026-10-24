/*
888. Fair Candy Swap

https://leetcode.com/problems/fair-candy-swap/
*/

function fairCandySwap(aliceSizes: number[], bobSizes: number[]): number[] {
  // Calculate the sum of candies for both Alice and Bob.
  let sumAlice = aliceSizes.reduce(
    (accumulated, current) => accumulated + current,
    0
  );
  let sumBob = bobSizes.reduce(
    (accumulated, current) => accumulated + current,
    0
  );

  // Calculate the difference in candies between Alice and Bob, divided by 2.
  let halfDiff = (sumAlice - sumBob) >> 1;

  // Create a set from Bob's candy sizes for constant-time lookups.
  let bobSizesSet = new Set(bobSizes);

  // Loop through each of Alice's candy sizes to find a fair swap.
  for (let aliceCandy of bobSizes) {
    // Calculate the target size for Bob that would equalize the sum.
    let targetBobCandy = aliceCandy - halfDiff;

    // Check if the target candy size exists in Bob's collection.
    if (bobSizesSet.has(targetBobCandy)) {
      // If found, return the pair of candy sizes for Alice and Bob.
      return [aliceCandy, targetBobCandy];
    }
  }

  return [];
}
