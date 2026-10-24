/*
341. Flatten Nested List Iterator

https://leetcode.com/problems/flatten-nested-list-iterator/
*/

class NestedInteger {
  constructor(value?: number) {}

  isInteger(): boolean {
    return false;
  }

  getInteger(): number | null {
    return 0;
  }

  setInteger(value: number) {}

  add(elem: NestedInteger) {}

  getList(): NestedInteger[] {
    return [];
  }
}

class NestedIterator {
  s: NestedInteger[] = [];
  constructor(nestedList: NestedInteger[]) {
    // 倒序插入
    for (let i = nestedList.length - 1; i >= 0; --i) {
      this.s.push(nestedList[i]);
    }
  }

  hasNext(): boolean {
    while (this.s.length > 0) {
      const t = this.s[this.s.length - 1];
      if (t.isInteger()) return true;
      this.s.pop();
      for (let i = t.getList().length - 1; i >= 0; --i) {
        this.s.push(t.getList()[i]);
      }
    }
    return false;
  }

  next(): number {
    const t = this.s.pop();
    return t!.getInteger()!;
  }
}
