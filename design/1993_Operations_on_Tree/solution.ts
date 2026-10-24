/*
1993. Operations on Tree

https://leetcode.com/problems/operations-on-tree/
*/

/*
    https://www.youtube.com/watch?v=qK4PtjrVD0U
*/
class LockingTree {
  private parent: number[];
  private lockUser: number[];
  private children: Map<number, number[]>;

  constructor(parent: number[]) {
    this.parent = parent;
    this.lockUser = Array(parent.length).fill(-1);
    this.children = new Map<number, number[]>();
    for (let child = 1; child < parent.length; child++) {
      if (!this.children.has(parent[child])) {
        this.children.set(parent[child], []);
      }
      this.children.get(parent[child])!.push(child);
    }
  }

  lock(num: number, user: number): boolean {
    if (this.lockUser[num] === -1) {
      this.lockUser[num] = user;
      return true;
    }
    return false;
  }

  unlock(num: number, user: number): boolean {
    if (this.lockUser[num] === user) {
      this.lockUser[num] = -1;
      return true;
    }
    return false;
  }

  upgrade(num: number, user: number): boolean {
    if (this.hasLockedAncestor(num)) {
      return false;
    }

    const unlockedCount = this.unlockDescendants(num);
    if (unlockedCount > 0) {
      this.lockUser[num] = user;
      return true;
    }

    return false;
  }
  private hasLockedAncestor(num: number): boolean {
    while (num !== -1) {
      if (this.lockUser[num] !== -1) {
        return true;
      }
      num = this.parent[num];
    }
    // 所有祖先在节点均未被锁定，返回 False
    return false;
  }

  private unlockDescendants(num: number): number {
    let count = 0;
    if (this.lockUser[num] !== -1) {
      count++;
      this.lockUser[num] = -1;
    }

    const children = this.children.get(num);
    if (children) {
      for (const child of children) {
        count += this.unlockDescendants(child);
      }
    }

    return count;
  }
}
