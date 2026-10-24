/*
399. Evaluate Division

https://leetcode.com/problems/evaluate-division/

Note: x/x is -1 if x is not in the graph
*/

/*
HuaHua: Union Find
https://www.youtube.com/watch?v=UwpvInpgFmo


Time complexity: O(E + Q)   E is the number of equations and Q is the number of queries
Space complexity: O(E)
*/

// A / B = 2
//      parents[A] = [B, 2]
//      parents[B] = [B, 1]
// B / C = 3
//      parents[C] = [B, 1.0/3]
type ParentMap = { [key: string]: [string, number] };

function calcEquation(
  equations: [string, string][],
  values: number[],
  queries: [string, string][]
): number[] {
  const parents: ParentMap = {};

  for (let i = 0; i < equations.length; ++i) {
    const [A, B] = equations[i];
    const k = values[i];
    // Neither is in the forest
    if (!parents[A] && !parents[B]) {
      parents[A] = [B, k];
      parents[B] = [B, 1.0];
    } else if (!parents[A]) {
      parents[A] = [B, k];
    } else if (!parents[B]) {
      parents[B] = [A, 1.0 / k];
    } else {
      const rA = find(A, parents);
      const rB = find(B, parents);
      parents[rA[0]] = [rB[0], (k / rA[1]) * rB[1]];
    }
  }

  const ans: number[] = [];
  for (const [X, Y] of queries) {
    if (!parents[X] || !parents[Y]) {
      ans.push(-1.0);
      continue;
    }
    const rX = find(X, parents);
    const rY = find(Y, parents);
    if (rX[0] !== rY[0]) {
      ans.push(-1.0);
    } else {
      ans.push(rX[1] / rY[1]);
    }
  }
  return ans;
}
function find(C: string, parents: ParentMap): [string, number] {
  if (C !== parents[C][0]) {
    const p = find(parents[C][0], parents);
    parents[C][0] = p[0];
    parents[C][1] *= p[1];
  }
  return parents[C];
}
