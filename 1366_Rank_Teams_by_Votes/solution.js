/*
1366. Rank Teams by Votes

Level: Medium

https://leetcode.com/problems/rank-teams-by-votes
*/

/*
  Solution: 
*/

/**
 * @param {string[]} votes
 * @return {string}
 */
var rankTeams = function (votes) {
  var n = votes[0].length;
  var ranks = {}; // {char: {position: votes}}

  votes.forEach((v) => {
    for (let i = 0; i < n; i++) {
      const t = v[i];
      if (ranks[t] === undefined) {
        ranks[t] = new Array(n).fill(0);
      }
      ranks[t][i]++;
    }
  });

  const res = Object.keys(ranks).sort((a, b) => {
    const listA = ranks[a];
    const listB = ranks[b];
    for (let i = 0; i < n; i++) {
      if (listA[i] != listB[i]) {
        return listA[i] - listB[i];
      }
    }
    return a > b ? 1 : -1;
  });

  return res.join('');
};

export { rankTeams };
