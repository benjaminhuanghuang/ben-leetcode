/*
981. Time Based Key-Value Store

Level: Medium

https://leetcode.com/problems/time-based-key-value-store
*/

/*
  Solution:  Binary Search,  Upper bound
*/

/**
 * Initialize your data structure here.
 */
var TimeMap = function () {
  this.map = {};
};

/**
 * @param {string} key
 * @param {string} value
 * @param {number} timestamp
 * @return {void}
 */
TimeMap.prototype.set = function (key, value, timestamp) {
  var list = this.map[key];
  if (list === undefined) {
    this.map[key] = [];
  }
  this.map[key].push([timestamp, value]);
};

/**
 * @param {string} key
 * @param {number} timestamp
 * @return {string}
 */
TimeMap.prototype.get = function (key, timestamp) {
  var list = this.map[key];
  if (list === undefined) {
    return "";
  }
  var n = list.length;
  if (timestamp >= list[n - 1][0]) {
    return list[n - 1][1];
  } else if (timestamp < list[0][0]) {
    return "";
  }

  // binary search
  let l = 0,
    r = n;
  while (l < r) {
    const mid = Math.floor((l + r) / 2);
    if (list[mid][0] <= timestamp) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return list[r - 1][1];
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * var obj = new TimeMap()
 * obj.set(key,value,timestamp)
 * var param_2 = obj.get(key,timestamp)
 */

export { twoSum };
