/*
721. Accounts Merge

https://leetcode.com/problems/accounts-merge/

[Facebook]


/*
Approach: Union Find
两条 account 可以被merge的条件是它们有相同的 email
*/

import { UnionFind } from "./unionfind";

function accountsMerge(accounts: string[][]): string[][] {
  const emailToID: Map<string, number> = new Map();
  const idToName: Map<number, string> = new Map();
  const uf = new UnionFind(accounts.length);

  // Step 1: Map each email to an account ID and union accounts with common emails
  for (let i = 0; i < accounts.length; i++) {
    const name = accounts[i][0];
    for (let j = 1; j < accounts[i].length; j++) {
      const email = accounts[i][j];
      if (!emailToID.has(email)) {
        emailToID.set(email, i);
      } else {
        uf.union(i, emailToID.get(email)!);
      }
      idToName.set(i, name);
    }
  }

  // Step 2: Collect emails for each connected component
  const idToEmails: Map<number, Set<string>> = new Map();
  for (const [email, id] of emailToID.entries()) {
    const rootID = uf.find(id);
    if (!idToEmails.has(rootID)) {
      idToEmails.set(rootID, new Set());
    }
    idToEmails.get(rootID)!.add(email);
  }

  // Step 3: Construct the result
  const res: string[][] = [];
  for (const [id, emails] of idToEmails.entries()) {
    const name = idToName.get(id);
    const sortedEmails = Array.from(emails).sort();
    res.push([name!, ...sortedEmails]);
  }

  return res;
}

export {};
