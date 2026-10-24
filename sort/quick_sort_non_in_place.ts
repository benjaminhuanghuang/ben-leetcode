/*
    Time complexity:  N*Lg(N)
    
    Spce complexity: Extra space is allocated for the partitioning step (e.g., allocating additional arrays for left and right partitions), 
    the space complexity can increase to O(N).
    O(n) in the worst case, particularly if the partitioning is done using auxiliary arrays or lists.

*/

function quickSortNonInPlace(arr: number[]): number[] {
  if (arr.length <= 1) {
    return arr;
  }

  // Get the pivot value at the middle
  const pivot = arr[Math.floor(arr.length / 2)];

  // Split the numbers into 3 parts: left(less than pivot value), pivot value, right(bigger than pivot value)
  const left = arr.filter((num) => num < pivot);
  const middle = arr.filter((num) => num === pivot);
  const right = arr.filter((num) => num > pivot);

  // recursive
  return [
    ...quickSortNonInPlace(left),
    ...middle,
    ...quickSortNonInPlace(right),
  ];
}
