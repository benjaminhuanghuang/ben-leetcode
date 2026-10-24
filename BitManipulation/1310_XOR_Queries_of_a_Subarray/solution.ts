/*
1310. XOR Queries of a Subarray

https://leetcode.com/problems/xor-queries-of-a-subarray/
*/

/*
XOR of [left...right]  = cumulative XORs right and left - 1. 
*/
function xorQueries(arr: number[], queries: number[][]): number[] {
  const len = arr.length;
  // Create an array to store the prefix XORs with an additional 0 at the beginning.
  const prefixXOR: number[] = new Array(len + 1).fill(0);

  // Calculate the prefix XOR values for the array.
  // The cumulative XOR s[i] at index i will be the XOR of all elements from arr[0] to arr[i - 1].
  for (let i = 0; i < len; ++i) {
    prefixXOR[i + 1] = prefixXOR[i] ^ arr[i]; // additional 0 at the beginning.
  }

  const results: number[] = [];

  // Process each query and calculate the XOR for the given range.
  for (const [left, right] of queries) {
    // XOR between the prefix XORs gives the XOR of the range.
    // there is additional 0 at the beginning.
    results.push(prefixXOR[right + 1] ^ prefixXOR[left]);
  }

  // Return the array of results.
  return results;
}
