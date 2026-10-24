/*
1337. The K Weakest Rows in a Matrix

https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
*/

function kWeakestRows(mat: number[][], k: number): number[] {
  function indexOfLastSolider(row: number[]): number {
    if (row[0] === 0) {
      return -1;
    }
    if (row[row.length - 1] === 1) {
      return row.length - 1;
    }

    let lo = 0;
    let hi = row.length - 1;

    while (lo <= hi) {
      const mid = Math.floor((lo + hi) / 2);

      if (row[mid] === 0) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    if (row[lo] === 1) {
      return lo;
    }

    return hi;
  }

  // Priority Queue?
  let weakestSet: number[][] = [];

  // O(mlogn) = O(m) * O(log(n))
  for (let i = 0; i < mat.length; i++) {
    const row = mat[i];
    const lastSoldier = indexOfLastSolider(row); // O(log(n))
    const level = lastSoldier + 1;

    // If we sorted it in, it would still be O(log(m))
    weakestSet.push([i, level]);
  }

  // O(mlog(m))
  return weakestSet
    .sort((a, b) => a[1] - b[1])
    .slice(0, k)
    .map((a) => a[0]);
}

function kWeakestRows_N(mat: number[][], k: number): number[] {
  let n = mat.length;
  const countArray: number[][] = [];
  for (let row = 0; row < mat.length; row++) {
    let soldierCount = 0;
    for (const col of mat[row]) {
      if (col === 1) {
        soldierCount++;
      } else {
        break; // importent for performance!
      }
    }
    countArray.push([soldierCount, row]);
  }
  // countArray.sort((a, b) => a[0] - b[0]);

  // const ans = [];
  // for(let i =0;i < k;i++){
  //     ans.push(countArray[i][1]);
  // }
  // return ans;

  return countArray
    .sort((a, b) => a[0] - b[0])
    .slice(0, k)
    .map((v) => v[1]);
}
