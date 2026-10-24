/*

Space complexity:
  O(logn) average space complexity, 
  O(n) worst-case space complexity.
  In the standard in-place version of quick sort, the space complexity is O(logn) on average, and O(n) in 
  the worst case due to the recursive nature of the algorithm and the space required for the call stack.
*/
export function quickSortInPlace(arr: number[]) {
  quickSort(arr, 0, arr.length - 1);
}

export function quickSort(arr: number[], low: number, high: number) {
  if (low < high) {
    const p = partition(arr, low, high);

    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
  }
}

function partition(arr: number[], low: number, high: number): number {
  const pivotValue = arr[high];
  let pivot = low;
  for (let i = low; i < high; i++) {
    if (arr[i] < pivotValue) {
      swap(arr, pivot, i);
      pivot++;
    }
  }
  swap(arr, pivot, high);
  return pivot;
}

function swap(arr: number[], a: number, b: number) {
  const tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}
