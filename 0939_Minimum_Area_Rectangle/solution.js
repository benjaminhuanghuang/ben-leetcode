/*
939. Minimum Area Rectangle

Level: Medium

https://leetcode.com/problems/minimum-area-rectangle
*/

/*
  Solution: 
*/

/**
 * @param {number[][]} points
 * @return {number}
 */
var minAreaRect = function (points) {
  const n = points.length;
  const grid = {};
  for (let i = 0; i < n; i++) {
    let p = point[i];
    const key = p[0] + "," + p[1];
    grid[key] = true;
  }

  let res = Number.MAX_SAFE_INTEGER;

  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const p1 = points[i], p2= points[j];
      const x1=p1[0],y1=p1[1],x2=p2[0],y2=p2[1];
      if(x1!=x2 && y1!=y2){
        if(grid[x1+','+y2]  && grid[x2+','+y1]){
          // find a Rectangle
          const area = Math.abs(y2-y1)* Math.abs(x2-x1);
          res = Math.min(area, res)
        }
      }
    }
  }
  return res;
};

export { twoSum };
