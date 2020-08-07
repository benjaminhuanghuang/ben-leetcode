/*
1338. Reduce Array Size to The Half

Level: Medium

https://leetcode.com/problems/reduce-array-size-to-the-half
*/

/*
  Solution: 
*/

/**
 * @param {number[]} arr
 * @return {number}
 */
var minSetSize = function (arr) {
  let map = {};
  arr.forEach((num) => {
    if (map[num] === undefined) {
      map[num] = 0;
    }
    map[num]++;
  });

  const n = arr.length;
  let curr = n,
    res = 0;
  const list = Object.keys(map).sort((a, b) => map[a] - map[b]);

  for (let i = 0; i < list.length; i++) {
    const n = list[i];
    curr -= map[n];
    res++;
    if (cur <= n / 2) break;
  }
  return res;
};

export { twoSum };
