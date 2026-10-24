const nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const mid = 8;

// Calculate the count of numbers that are greater than or equal to mid
const count = nums.reduce(
  (accumulator, value) => accumulator + (value >= mid ? 1 : 0),
  0
);

const sum = nums.reduce((accumulator, value) => accumulator + value, 0);
// for (auto x: nums)
//    if (x>=mid) count++;
