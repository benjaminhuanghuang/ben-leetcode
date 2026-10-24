/*
721. Accounts Merge

https://leetcode.com/problems/accounts-merge/

[Facebook]


/*
Approach: Graph DFS
the input looks like
["name", "email1", "email2", "email3", ...]

Build a graph to connect all account liked to the same email

*/

function accountsMerge(accounts: string[][]): string[][] {
  // build the graph
  const n = accounts.length;
  const graph: number[][] = Array.from({ length: n }, () => []);

  for (let i = 0; i < n; i++) {
    const emails = new Set(accounts[i].slice(1));
    //
    for (let j = 0; j < i; j++) {
      if (accounts[i][0] !== accounts[j][0]) {
        continue;
      }
      for (let k = 1; k < accounts[j].length; k++) {
        if (emails.has(accounts[j][k])) {
          graph[i].push(j);
          graph[j].push(i);
          break;
        }
      }
    }
  }

  const res: string[][] = [];
  const visited: boolean[] = Array(n).fill(false);

  for (let i = 0; i < accounts.length; i++) {
    if (!visited[i]) {
      const emailSet: Set<string> = new Set();
      dfs(graph, accounts, i, visited, emailSet);
      const mergedAccount = [accounts[i][0]];
      emailSet.forEach((email) => mergedAccount.push(email));
      res.push(mergedAccount);
    }
  }

  return res;
}

function dfs(
  graph: number[][],
  accounts: string[][],
  i: number,
  visited: boolean[],
  emailSet: Set<string>
): void {
  if (visited[i]) return;

  visited[i] = true;
  for (let j = 1; j < accounts[i].length; j++) {
    emailSet.add(accounts[i][j]);
  }

  for (const neighbor of graph[i]) {
    if (!visited[neighbor]) {
      dfs(graph, accounts, neighbor, visited, emailSet);
    }
  }
}

/*
Approach: Graph + DFS Based on Approach 1, use a email->id map
to speed up the graph building process.
*/
function accountsMerge2(accounts: string[][]): string[][] {
  const n = accounts.length;
  const graph: number[][] = Array.from({ length: n }, () => []);
  const emailToIds: Map<string, number[]> = new Map();

  // Map each email to a list of account IDs
  for (let i = 0; i < n; i++) {
    for (let j = 1; j < accounts[i].length; j++) {
      const email = accounts[i][j];
      if (!emailToIds.has(email)) {
        emailToIds.set(email, []);
      }
      emailToIds.get(email)?.push(i);
    }
  }

  // Build the graph by connecting account IDs that share the same email
  for (let ids of emailToIds.values()) {
    for (let i = 1; i < ids.length; i++) {
      graph[ids[0]].push(ids[i]);
      graph[ids[i]].push(ids[0]);
    }
  }

  const res: string[][] = [];
  const visited: boolean[] = Array(n).fill(false);

  // Perform DFS for each account
  for (let i = 0; i < accounts.length; i++) {
    if (!visited[i]) {
      const emailSet: Set<string> = new Set();
      dfs2(graph, accounts, i, visited, emailSet);
      const accountName = [accounts[i][0]];
      // get the emails belonging to the account
      const sortedEmails = Array.from(emailSet).sort();
      res.push(accountName.concat(sortedEmails));
    }
  }

  return res;
}

function dfs2(
  graph: number[][],
  accounts: string[][],
  i: number,
  visited: boolean[],
  emailSet: Set<string>
): void {
  if (visited[i]) return; //account[i] has been visited

  visited[i] = true;
  for (let j = 1; j < accounts[i].length; j++) {
    emailSet.add(accounts[i][j]);
  }

  for (const neighbor of graph[i]) {
    if (!visited[neighbor]) {
      dfs2(graph, accounts, neighbor, visited, emailSet);
    }
  }
}

export {};
