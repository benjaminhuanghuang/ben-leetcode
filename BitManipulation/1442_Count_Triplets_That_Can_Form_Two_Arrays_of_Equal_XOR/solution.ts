/*
1442. Count Triplets That Can Form Two Arrays of Equal XOR

https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
*/

/*
X = a0 ^ a1 ^ ... ^ ai-1
Y = a0 ^ a1 ^ ... ^ ai-1 ^ ai ^ ...^ aj-1
Z = a0 ^ a1 ^ ... ^ ai-1 ^ ai ^ ...^ aj-1 ^ aj ^ ... ^ ak

X ^ Y = ai ^ ...^ aj-1
Y ^ Z = aj ^ ... ^ ak
*/
function countTriplets(arr: number[]): number {
  const n = arr.length;
  let count = 0;
  //This allows us to efficiently calculate the XOR of any subarray.
  const prefixXOR = new Array(n + 1).fill(0);

  // Calculate prefix XOR array
  for (let i = 0; i < n; i++) {
    prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
  }

  // Check all possible triplets
  for (let i = 0; i < n; i++) {
    for (let k = i + 1; k < n; k++) {
      if (prefixXOR[i] === prefixXOR[k + 1]) {
        //If true, it means the XOR of elements from i to k is 0.

        //Any value of j between i+1 and k+1 (exclusive) forms a valid triplet.
        count += k - i;
      }
    }
  }

  return count;
}

function countTriplets_better(arr: number[]): number {
  const n = arr.length;
  const ps: number[] = new Array(n + 1).fill(0);

  for (let i = 0; i < n; i++) {
    ps[i + 1] = ps[i] ^ arr[i];
  }

  let res = 0;

  for (let i = 0; i < n - 1; i++) {
    for (let j = i + 1; j < n; j++) {
      for (let k = j; k < n; k++) {
        if ((ps[i] ^ ps[j]) === (ps[j] ^ ps[k + 1])) {
          res += 1;
        }
      }
    }
  }

  return res;
}
