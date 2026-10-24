/*
311. Sparse Matrix Multiplication

https://leetcode.com/problems/sparse-matrix-multiplication/
*/

/*
https://algo.monster/liteproblems/311
*/

function multiply(mat1: number[][], mat2: number[][]): number[][] {
  // Get the dimensions required for the resulting matrix
  const numRowsOfMat1: number = mat1.length; // Number of rows in mat1
  const numColsOfMat2: number = mat2[0].length; // Number of columns in mat2

  // Initialize the resulting matrix with zeros
  const resultMatrix: number[][] = Array.from({ length: numRowsOfMat1 }, () =>
    Array.from({ length: numColsOfMat2 }, () => 0)
  );

  // Function to filter out all zero values and keep only non-zero values with their column index
  const filterZeros = (matrix: number[][]): [number, number][][] => {
    const numRows: number = matrix.length; // Number of rows in the given matrix
    const nonZeroValues: [number, number][][] = Array.from(
      { length: numRows },
      () => []
    );

    for (let row = 0; row < numRows; ++row) {
      for (let col = 0; col < matrix[row].length; ++col) {
        if (matrix[row][col] !== 0) {
          nonZeroValues[row].push([col, matrix[row][col]]);
        }
      }
    }
    return nonZeroValues;
  };

  // Get non-zero values for both matrices
  const filteredMat1: [number, number][][] = filterZeros(mat1);
  const filteredMat2: [number, number][][] = filterZeros(mat2);

  // Perform matrix multiplication using the sparse representations
  for (let i = 0; i < numRowsOfMat1; ++i) {
    for (const [colIndexOfMat1, valueOfMat1] of filteredMat1[i]) {
      for (const [colIndexOfMat2, valueOfMat2] of filteredMat2[
        colIndexOfMat1
      ]) {
        resultMatrix[i][colIndexOfMat2] += valueOfMat1 * valueOfMat2;
      }
    }
  }

  // Return the resulting matrix after multiplication
  return resultMatrix;
}
