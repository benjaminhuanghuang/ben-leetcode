/*
406. Queue Reconstruction by Height

Level: Medium

https://leetcode.com/problems/queue-reconstruction-by-height
*/

/*
  Solution: 
*/


/**
 * @param {number[][]} people
 * @return {number[][]}
 */
var reconstructQueue = function (people) {
  people.sort(sortPeople);
  var res = [], i;
  //Reconstruct queue by inserting people by its k value
  for (i = 0; i < people.length; i++) {
    res.splice(people[i][1], 0, people[i]);
  }
  return res;
};

var sortPeople = function (a, b) {
  //Sort people by height as the first priority decreasingly, and by order as the second priority non-decreasingly
  if (a[0] != b[0]) {
    return b[0] - a[0];
  } else {
    return a[1] - b[1];
  }
}


export { reconstructQueue };