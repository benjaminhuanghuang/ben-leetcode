/*
Methods like .forEach(), .map(), .reduce() ignore empty slots:
*/
Array(5).forEach((item) => console.log(item)); // does not print anything

console.log(Array(5)); //empty slots, not undefined values.
console.log(Array.from({ length: 5 })); // [undefined, undefined, undefined, undefined, undefined]
Array.from({ length: 5 }).forEach((item) => console.log(item)); // prints undefined 5 times

const arr = Array(5).map((item) => 0); // [ <5 empty items> ]
console.log(arr);

const arr2 = Array.from({ length: 5 }).map((item) => 0);
console.log(arr2); // [0, 0, 0, 0, 0]

const arr3 = Array.from({ length: 5 }, (element, i) => i);
console.log("arr3", arr3); // [0, 1, 2, 3, 4]

/*
Fill with constant: Array.from(...).fill()
*/
const rows = 3;
const cols = 4;

const matrix = Array.from({ length: rows }, () => Array(cols).fill(0));
console.log(matrix);

/*
Fill dynamically: Nested Array.from()
*/
const matrix2 = Array.from({ length: rows }, (_, rowIndex) =>
  Array.from({ length: cols }, (_, colIndex) => rowIndex + colIndex)
);
console.log(matrix2);

/*-------
DP
-------*/
const n = 10;
const dp: number[][] = Array.from({ length: n }, () => Array(n).fill(0));

/*-------
Graph
-------*/
let graph: Set<number>[] = Array(n)
  .fill(null)
  .map(() => new Set<number>());

graph = Array.from({ length: 5 }, () => new Set<number>());

const states: number[][] = Array(10).fill(6);

const answer: number[][] = Array.from({ length: 10 }, () => Array(5));

// Initialize the answer array with the specified number of rows and columns
const answer2: Array<Array<number>> = Array.from({ length: 5 }, () => Array(5));

// Function to create a 2D array and fill it
function create2DArray(
  rows: number,
  cols: number,
  initialValue: number
): number[][] {
  return Array.from({ length: rows }, () => new Array(cols).fill(initialValue));
}

/*
Wrong! 
Every row points to the same array, Modifying one element will modify all rows.
*/
const wrong = new Array(3).fill(Array(4).fill(0));
