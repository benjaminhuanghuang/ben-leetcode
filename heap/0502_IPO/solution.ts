/*
502. IPO

https://leetcode-cn.com/problems/ipo/

[Microsoft]
*/
import { PriorityQueue } from "./PriorityQueue";

/*
1. zip capital and profit to a pair array, [(capital0, profit0), (capital1, profit1), ...]
2. sort the pair array by capital, so we can get the project with the least capital requirement at the beginning
3. go through the pair array, if the capital is less than W, push the (captital, profit) pair to the max heap
4. pop the max heap to get the most profitable project we can afford

Time complexity: O(NlogN + KlogN), where N is the number of projects, K is the number of projects we can do
NlogN is for sorting the pair array by capital
KlogN is for going through the pair array and push the projects we can afford to the max heap

Space complexity: O(N)
*/
function findMaximizedCapital(
  k: number,
  W: number,
  Profits: number[],
  Capital: number[]
): number {
  // Zip capital and profit to a pair array
  const pairCapitalProfitPair: number[][] = [];
  for (let i = 0; i < Profits.length; i++) {
    pairCapitalProfitPair.push([Capital[i], Profits[i]]);
  }
  // Sort the pair array by capital
  pairCapitalProfitPair.sort((a, b) => a[0] - b[0]);

  // Initialize a max heap pick pairCapitalProfitPair with max profit
  const maxHeap = new PriorityQueue((a: number[], b: number[]) => a[1] > b[1]);
  let projectIndex = 0;
  for (let i = 0; i < k; i++) {
    // Push all projects can be started
    while (
      projectIndex < pairCapitalProfitPair.length &&
      pairCapitalProfitPair[projectIndex][0] <= W
    ) {
      maxHeap.add(pairCapitalProfitPair[projectIndex]);
      projectIndex++;
    }

    if (maxHeap.isEmpty()) {
      return W;
    }
    W += maxHeap.poll()![1];
  }

  return W;
}

/*
https://algo.monster/liteproblems/502.IPO

*/
// A function that maximizes the capital by doing at most 'k' projects
// starting with initial capital 'W'. Projects have associated profits
// and capital requirements.
type ProfitCapitalPair = { capital: number; profit: number };
function findMaximizedCapital_TLE(
  k: number,
  W: number,
  Profits: number[],
  Capital: number[]
): number {
  // Initialize a min-heap based on capital requirements so the project
  // with the least capital requirement is at the beginning.
  let minCapitalHeap: ProfitCapitalPair[] = [];

  // Populate the min-heap with capital and profits of the projects.
  for (let i = 0; i < Profits.length; ++i) {
    minCapitalHeap.push({ capital: Capital[i], profit: Profits[i] });
  }
  // Sort the heap to ensure the smallest capital requirement is at the start.
  minCapitalHeap.sort((a, b) => a.capital - b.capital);

  // Initialize an array to use as a max-heap to store profits
  // of the projects we can afford, enabling us to choose the most profitable one.
  let maxProfitHeap: number[] = [];

  // Define a helper function to turn the array into a max-heap,
  // using simple push-pop since TypeScript/JavaScript does not have a native priority queue structure.
  const pushMaxHeap = (value: number) => {
    maxProfitHeap.push(value);
    maxProfitHeap.sort((a, b) => b - a); // Sort in descending order to keep max element at the start
  };

  const popMaxHeap = (): number => {
    return maxProfitHeap.shift() || 0; // Remove and return the first element (max element)
  };

  // Loop to perform up to 'k' investments.
  for (let i = 0; i < k; i++) {
    // Move all projects we can afford (with current capital 'W') to the max-heap.
    while (minCapitalHeap.length && minCapitalHeap[0].capital <= W) {
      const project = minCapitalHeap.shift()!;
      pushMaxHeap(project.profit);
    }

    // If we cannot afford any project, exit the loop.
    if (!maxProfitHeap.length) {
      break;
    }

    // Pick the most profitable project we can afford and increase our capital.
    W += popMaxHeap();
  }

  // After completing 'k' or the maximum number of profitable investments,
  // 'W' is our maximized capital.
  return W;
}

export { findMaximizedCapital };
