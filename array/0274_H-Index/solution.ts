/*
274. H-Index

https://leetcode.com/problems/h-index/

citations: [3, 0, 6, 1, 5], citations[i] is the number of papers with reference i.
H index H(hight citation) means there are at least h papers with h citations.
*/

/*
         1  H=1, 1 paper has at least 1 citation
       2    H=2
     3      H=3
   x    
[0,1,3,5,6]


*/
function hIndex(citations: number[]): number {
  // sort the citations in ascending order
  citations.sort((a, b) => a - b);

  const n = citations.length;
  let h = 1;

  for (let i = n - 1; i >= 0; i--) {
    if (citations[i] >= h) {
      h++;
    } else {
      break;
    }
  }

  return h - 1;
}
