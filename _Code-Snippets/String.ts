// string * N
const str = "abc";
console.log(str.repeat(3)); // abcabcabc

// Sort string
const sorted = Array.from(str).sort().join("");

// Replace character at specific index in a string
function replaceCharAt(str: string, index: number, replacement: string) {
  if (index < 0 || index >= str.length) {
    throw new Error("Index out of bounds");
  }
  return str.substring(0, index) + replacement + str.substring(index + 1);
}

// Get char from ASCII code
console.log(String.fromCharCode(97)); // a
for (let k = 0; k < 26; k++) {
  console.log(String.fromCharCode(97 + k)); // a b c ... z
}

// Replace
let s = "";
s = s.replace(/[^a-zA-Z0-9]/g, "").toLowerCase();

// Function to check if a string contains only letters
function isOnlyLetters(str: string) {
  return /^[a-zA-Z]+$/.test(str);
}

// Function to check if a string contains only numbers
function isOnlyNumbers(str: string) {
  return /^[0-9]+$/.test(str);
}

// Function to check if a string contains both letters and numbers
function containsLettersAndNumbers(str: string) {
  return /[a-zA-Z]/.test(str) && /[0-9]/.test(str);
}

function isAlphanumeric(str: string) {
  return /[a-zA-Z]/.test(str) || /[0-9]/.test(str);
}

function isAlphanumeric2(str: string) {
  return (str >= "a" && str <= "z") || (str >= "0" && str <= "9");
}

/*--------------------------------
// Convert a string to uppercase using ASCII values
---------------------------------*/
function toUpperCaseUsingASCII(char: string): string {
  const asciiCode = char.charCodeAt(0);

  // Check if the character is a lowercase letter (a-z)
  if (asciiCode >= 97 && asciiCode <= 122) {
    // Convert to uppercase by subtracting 32 from the ASCII code
    return String.fromCharCode(asciiCode - 32);
  }

  // If the character is not a lowercase letter, return it as is
  return char;
}

// Example usage
console.log(toUpperCaseUsingASCII("a")); // Output: 'A'
console.log(toUpperCaseUsingASCII("z")); // Output: 'Z'
console.log(toUpperCaseUsingASCII("A")); // Output: 'A'
console.log(toUpperCaseUsingASCII("1")); // Output: '1'

// split string
function countSegments(s: string): number {
  const res = s.match(new RegExp(/\S+/, "g"));
  return res === null ? 0 : res.length;
}

// lowercase to uppercase
const S = ["a", "b", "c"];
const i = 0;
S[i] = String.fromCharCode(S[i].charCodeAt(0) ^ (1 << 5));
// Backtrack
S[i] = String.fromCharCode(S[i].charCodeAt(0) ^ (1 << 5));
