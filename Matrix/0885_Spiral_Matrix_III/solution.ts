/*
885. Spiral Matrix III

https://leetcode.com/problems/spiral-matrix-iii/
*/

function spiralMatrixIII(
  rows: number,
  cols: number,
  rStart: number,
  cStart: number
): number[][] {
  const totalCells: number = rows * cols;
  const answer: number[][] = [[rStart, cStart]];

  if (totalCells === 1) {
    return answer;
  }

  // Loop wherein each iteration potentially adds two sides of the spiral.
  for (let stepIncrease = 1; ; stepIncrease += 2) {
    // Directions are East, South, West, North.
    // Each tuple contains the row and column increments, and the number of steps to take.
    const directions: [number, number, number][] = [
      [0, 1, stepIncrease], // Move right (East)
      [1, 0, stepIncrease], // Move down (South)
      [0, -1, stepIncrease + 1], // Move left (West)
      [-1, 0, stepIncrease + 1], // Move up (North)
    ];

    for (const [rowIncrement, colIncrement, steps] of directions) {
      // Initialize a variable for the number of steps to be taken in the current direction
      let stepsRemaining = steps;

      // Move the number of steps in the current direction
      while (stepsRemaining-- > 0) {
        // Update the starting position
        rStart += rowIncrement;
        cStart += colIncrement;

        // Check if the new position is within the matrix bounds
        if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
          answer.push([rStart, cStart]);
          if (answer.length === totalCells) {
            return answer;
          }
        }
      }
    }
  }
}
