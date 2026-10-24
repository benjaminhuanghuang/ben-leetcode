/*
433. Minimum Genetic Mutation

https://leetcode.com/problems/minimum-genetic-mutation/
*/

function minMutation(
  startGene: string,
  endGene: string,
  bank: string[]
): number {
  const queue: string[] = [];
  queue.push(startGene);

  // Visited set
  const visited: Set<string> = new Set();
  visited.add(startGene);

  let mutations = 0;
  while (queue.length > 0) {
    let size = queue.length;
    while (size--) {
      let curr = queue.shift()!;
      if (curr === endGene) {
        return mutations;
      }
      for (const gene of bank) {
        if (visited.has(gene) || !validMutation(curr, gene)) {
          continue;
        }
        visited.add(gene);
        queue.push(gene);
      }
    }
    mutations++;
  }
  return -1;
}

function validMutation(s1: string, s2: string): boolean {
  let count = 0;
  for (let i = 0; i < s1.length; ++i) {
    if (s1[i] !== s2[i] && ++count > 1) {
      return false;
    }
  }
  return count === 1;
}
