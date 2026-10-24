// Create a new Set
const mySet = new Set();

// Add values to the Set
mySet.add(1);
mySet.add(2);
mySet.add(3);

// Check if a value exists in the Set
console.log(mySet.has(3)); // Output: true
console.log(mySet.has(6)); // Output: false

// Create a new Set with initial values
const bracesMap: Map<string, string> = new Map([
  ["}", "{"],
  ["]", "["],
  [")", "("],
]);
const opening = new Set(bracesMap.values());

// Set < -- > Array
const nums = [1, 2, 4, 5, 8, 7];
let arraySet = new Set(nums);
// Convert set back to array
let uniqueArray = Array.from(arraySet);

/*
Char set from string
*/
const charSet = new Set("hello world");
console.log(charSet); // Output: Set { 'h', 'e', 'l', 'o', ' ', 'w', 'r', 'd' }
