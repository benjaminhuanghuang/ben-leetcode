/*
284. Peeking Iterator

https://leetcode.com/problems/peeking-iterator/
*/

interface Iterator {
  hasNext(): boolean;
  next(): number;
  peek(): number;
}

class PeekingIterator {
  /*
    设一个 peeked 的flag 同时 保存 peeked 过得值.  
    如果已经peeked过了, next()直接返回保存的值即可.
	*/
  peeked: boolean;
  peekVal: number = -1; // cache the peeked value
  iterator: Iterator;

  constructor(iterator: Iterator) {
    this.peeked = false;
    this.iterator = iterator;
  }

  peek(): number {
    if (this.peeked) return this.peekVal;

    this.peeked = true;
    this.peekVal = this.iterator.next();

    return this.peekVal;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  next(): number {
    if (!this.peeked) {
      this.peekVal = this.iterator.next();
    }
    this.peeked = false;
    return this.peekVal;
  }

  hasNext(): boolean {
    return this.iterator.hasNext() || this.peeked;
  }
}

export {};
