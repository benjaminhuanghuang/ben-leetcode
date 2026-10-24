// Helper function to check if a string is a numeric value.
function isNumeric(token: string): boolean {
  return !isNaN(parseFloat(token)) && isFinite(Number(token));
}

// parseXXX() functions stop parsing when they encounter a character that is not a valid part of the number.
let str = "12x3.45xxx";
let num = parseFloat(str);
console.log(num); // 12

str = "123";
num = parseInt(str, 10);

// Number: If any part of the string is not a valid number, it returns NaN.
str = "123";
num = Number(str);
console.log(num); // 123

export {};
