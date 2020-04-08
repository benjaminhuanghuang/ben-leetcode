/*
56. Merge Intervals

Level: Nediun

https://leetcode.com/problems/merge-intervals/
*/

/*
  Solution: 
*/

var merge = function(intervals) {
  if (intervals.length <= 1) {
    return arr;
  }
  // Sort the intervals 
  intervals.sort((a,b)=> {
    return a[0] -  b[0];
  })

  let result = [];
  let start = arr[0];
  
  for (let i = 1; i < intervals.length; i++) {
    let current = intervals[i];

    
    if (start[1] >= current[0]) {
      // there is a overlap
      let merged = [];
      if (start[1] <= current[1]) {
        merged = [start[0],current[1]];
      } else {
        merged = [start[0],start[1]];
      }
      start = merged;
    } else {
      result.push(start);
      start = current;
    }
  }
  result.push(start);
  return result;
};


export { merge };