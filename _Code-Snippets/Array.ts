// Create Array 3: from another array
const map = new Map([
  ["}", "{"],
  ["]", "["],
  [")", "("],
]);
const openingBraces = Array.from(map.values());

// Create Array and fill with value
const dp = Array(10).fill(0);
//-2d
const rows = 10;
const cols = 9;
const visited = Array.from({ length: rows }, () => Array(cols).fill(false));

const nums = [1, 2, 3];
const used: boolean[] = Array(nums.length).fill(false);

// Is element included in array?
if (openingBraces.includes("(")) {
  // if is open Brace
}

// loop through value, index
const target = 9;
nums.forEach((v, i) => {});

// Sort
// Sort number
const coins = [1, 2, 3];
//If a - b is less than 0, a is placed before b.
coins.sort((a, b) => b - a);
// Sort string
let str = "javascript";
let sortedStr = str.split("").sort().join("");
console.log(sortedStr); // Output: "aacijprstv"

// Sort strings by element length
let stringsArray = ["apple", "banana", "pear", "grapefruit", "orange"];
// When a.length - b.length is negative, a comes before b in the sorted array
stringsArray.sort((a, b) => a.length - b.length);
// Sort the array based on both alphabetical order and length
stringsArray.sort((a, b) => {
  // Compare by length first (ascending)
  if (a.length !== b.length) {
    return a.length - b.length;
  }
  // If lengths are the same, compare alphabetically
  return a.localeCompare(b);
});

// Sum
let numbers = [1, 2, 3, 4, 5];
let sum = numbers.reduce(
  (accumulator, currentValue) => accumulator + currentValue,
  0
);
console.log(sum); // Output: 15

// Max
const max = Math.max(...nums);

export {};
