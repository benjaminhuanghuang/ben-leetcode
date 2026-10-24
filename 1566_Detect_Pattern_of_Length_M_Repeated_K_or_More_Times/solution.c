#include <stdbool.h>

/*
Walk the array comparing arr[i] to arr[i - m]. Count consecutive matches;
a run of m*(k-1) consecutive matches means the length-m pattern ending at
i - m*(k-1) repeats k times in a row. Any mismatch resets the count.

Time complexity: O(n)
Space complexity: O(1)
*/
bool containsPattern(int* arr, int arrSize, int m, int k) {
  int need = m * (k - 1);
  int count = 0;

  for (int i = m; i < arrSize; i++) {
    if (arr[i] == arr[i - m]) {
      count++;
      if (count >= need) return true;
    } else {
      count = 0;
    }
  }

  return false;
}
