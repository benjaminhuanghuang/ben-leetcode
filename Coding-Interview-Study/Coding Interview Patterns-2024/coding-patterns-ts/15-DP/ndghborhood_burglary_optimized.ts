function neighborhoodBurglaryOptimized(houses: number[]): number {
  if (houses.length === 0) {
    return 0;
  }
  if (houses.length === 1) {
    return houses[0];
  }

  // Initialize base cases
  let prevPrevMaxProfit = houses[0];
  let prevMaxProfit = Math.max(houses[0], houses[1]);

  // Compute the max profit iteratively
  for (let i = 2; i < houses.length; i++) {
    const currMaxProfit = Math.max(
      prevMaxProfit,
      houses[i] + prevPrevMaxProfit
    );
    prevPrevMaxProfit = prevMaxProfit;
    prevMaxProfit = currMaxProfit;
  }

  return prevMaxProfit;
}
/*

space complexity to O(1)
*/
