type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (
  arr: MultiDimensionalArray,
  n: number
): MultiDimensionalArray {
  if (n <= 0) return arr;

  const result: MultiDimensionalArray = [];

  for (const value of arr) {
    if (typeof value === "number") {
      result.push(value);
    } else {
      result.push(...flat(value, n - 1));
    }
  }

  return result;
};
