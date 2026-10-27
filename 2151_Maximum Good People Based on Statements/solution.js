/*
2151. Maximum Good People Based on Statements

Hard

根据statement 判断有多少好人
https://leetcode.com/problems/maximum-good-people-based-on-statements/
*/

/*
  Good people's stametemt must be consitent
  good ones must be in the combo
  bad ones must NOT be in the combo
*/
/**
 * @param {number[][]} statements
 * @return {number}
 */
var maximumGood = function (statements) {
  let n = statements.length;
  for (let k = n; k >= 1; k--) {
    const state = (1 << k) - 1;
    while (state < 1 << m) {
      if (checkOK(state, statements)) return k;

      let c = state & -state;
      let r = state + c;
      state = (((r ^ state) >> 2) / c) | r;
    }
  }
  return 0;
};
