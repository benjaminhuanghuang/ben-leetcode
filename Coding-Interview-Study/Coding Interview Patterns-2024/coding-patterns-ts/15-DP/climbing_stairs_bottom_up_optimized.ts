function climbingStairsBottomUpOptimized(n: number): number {
  if (n <= 2) {
    return n;
  }

  // Base cases
  let oneStepBefore = 2;
  let twoStepsBefore = 1;

  for (let i = 3; i <= n; i++) {
    const current = oneStepBefore + twoStepsBefore;
    twoStepsBefore = oneStepBefore;
    oneStepBefore = current;
  }

  return oneStepBefore;
}

/*
time complexity of O(n), 

space complexity to O(1).
*/
