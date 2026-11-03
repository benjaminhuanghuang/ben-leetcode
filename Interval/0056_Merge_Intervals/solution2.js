/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
  intervals.sort((a, b) => a[0] - b[0]);

  return intervals.reduce((acc, curr) => {
    const last = acc[acc.length - 1];
    // 如果结果集为空，或当前区间起点大于前一个区间的终点（无重叠）
    if (!last || curr[0] > last[1]) {
      acc.push(curr);
    } else {
      // 重叠：就地更新右端点
      last[1] = Math.max(last[1], curr[1]);
    }

    return acc;
  }, []);
};
