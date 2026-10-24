// Create a map 1: using Plain JavaScript Object
let myMap: { [key: string]: number } = {};

// Adding entries to the map
myMap["one"] = 1;
myMap["two"] = 2;
myMap["three"] = 3;

// Create a map 2:  using TypeScript's Map class
let myMap2 = new Map<string, number>();

// Adding entries to the map
myMap2.set("one", 1);
myMap2.set("two", 2);
myMap2.set("three", 3);

// Accessing values from the map
console.log(myMap2.get("two")); // Output: 2

// Create map 3: pass an iterable object (like an array) of key-value pairs
const myMap3 = new Map([
  ["key1", "value1"],
  ["key2", "value2"],
  ["key3", "value3"],
]);

// Accessing values in the Map
console.log(myMap3.get("key1")); // Output: 'value1'

// values() method of Map instances returns a new map iterator object that contains the values for each element in this map in insertion order.
const values = myMap2.values();
const keys = myMap2.keys();

// Check if a key exists in the Map
console.log(myMap2.has("key1")); // Output: true
console.log(myMap2.has("key4")); // Output: false

// Get default value if key doesn't exist
myMap2.get("keyN") || 0;

/*------------------------------------
// Iterating over a Map
------------------------------------*/
const map = new Map<string, number>();

map.set("one", 1);
map.set("two", 2);
map.set("three", 3);

// Iterate over all key-value pairs in the map
for (const [key, value] of map.entries()) {
  console.log(`Key: ${key}, Value: ${value}`);
}

/*------------------------------------
// Using object as a map

Note:
wordPattern['constructor'] will return the constructor function of the object.
if you use if (!wordPattern[word]) to check if the key exists, it will return true unepectedly

Using (word in wordPattern) also has this issue.

290. Word Pattern
------------------------------------*/
const romanToIntMap: { [key: string]: number } = {
  I: 1,
  V: 5,
  X: 10,
  L: 50,
  C: 100,
  D: 500,
  M: 1000,
};
const romanStr: string = "IVX";
const curr = romanToIntMap[romanStr[1]];

const stMap: { [key: string]: string } = {};
if (!stMap["a"]) {
  // if sChar is not in the map, add it
  stMap["a"] = "b";
}

const charFreq: { [key: string]: number } = {};
// DO NOT use if(charFreq[s[right]]), when  charFreq[s[right]] === 0, it will be false
if (charFreq["a"] !== undefined) {
  // If s[right] is in t
}

/*------------------------------------
 Get the first key
*/
const wordCount = new Map<string, number>();

// Set some key-value pairs
wordCount.set("one", 1);
wordCount.set("two", 2);
wordCount.set("three", 3);

// Get an iterator over the keys
const keysIterator = wordCount.keys();

// Get the first key
const firstKey = keysIterator.next().value;
