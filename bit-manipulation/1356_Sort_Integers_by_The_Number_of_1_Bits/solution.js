/*
  Solution: 
*/

function sortByBits(arr) {
  const countBits = (n) => {
    let count = 0;
    while (n) {
      count += n & 1;
      n >>>= 1;
    }
    return count;
  };

  return arr.slice().sort((a, b) => countBits(a) - countBits(b) || a - b);
}
