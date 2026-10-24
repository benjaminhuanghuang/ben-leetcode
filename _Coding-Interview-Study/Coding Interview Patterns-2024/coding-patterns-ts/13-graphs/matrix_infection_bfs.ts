/*
0: Empty cell
1: Uninfected cell
2: Infected cell

Time complexity: The time complexity of matrix_infection is O(m x n), where m denotes the
number of rows, and n denotes the number of columns. This is because in the worst case, every
cell in the matrix is explored during level-order traversal.

Space complexity: The space complexity is O(m x n), primarily due to the queue, which can store
up to, m x n cells.
*/

import { isWithinBounds, dirs } from "./graph";

function matrixInfection(matrix: number[][]): number {
  const queue: [number, number][] = [];
  let uninfectedCells = 0;
  let seconds = 0;

  // Count the total number of uninfected cells and add each infected
  // cell to the queue to represent level 0 of the level-order
  // traversal.
  for (let r = 0; r < matrix.length; r++) {
    for (let c = 0; c < matrix[0].length; c++) {
      if (matrix[r][c] === 1) {
        uninfectedCells += 1;
      } else if (matrix[r][c] === 2) {
        queue.push([r, c]);
      }
    }
  }

  // Use level-order traversal to determine how long it takes to
  // infect the uninfected cells.
  while (queue.length > 0 && uninfectedCells > 0) {
    // 1 second passes with each level of the matrix that's explored.
    seconds += 1;
    const levelSize = queue.length;

    for (let i = 0; i < levelSize; i++) {
      const [r, c] = queue.shift()!;

      // Infect any neighboring 1s and add them to the queue to be
      // processed in the next level.
      for (const d of dirs) {
        const nextR = r + d[0];
        const nextC = c + d[1];

        if (
          isWithinBounds(nextR, nextC, matrix) &&
          matrix[nextR][nextC] === 1
        ) {
          matrix[nextR][nextC] = 2;
          uninfectedCells -= 1;
          queue.push([nextR, nextC]);
        }
      }
    }
  }

  // If there are still uninfected cells left, return -1. Otherwise,
  // return the time passed.
  return uninfectedCells === 0 ? seconds : -1;
}
