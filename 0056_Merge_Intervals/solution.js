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
  
  for (let i = 0; i < intervals.length; i++) {
    let newInterval = [intervals[i][0], intervals[i][1]];
    while(i < intervals.length - 1 && newInterval[1] >= intervals[i + 1][0]){
      // when newInterval has overlap with intervals[i + 1]
      newInterval[1] = Math.max(newInterval[1], intervals[i + 1][1])
      i++;
    } 
    result.push(newInterval) 
  }
  return result;
};


export { merge };