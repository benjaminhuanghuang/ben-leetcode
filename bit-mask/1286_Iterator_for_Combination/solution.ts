/*
1286. Iterator for Combination

https://leetcode.com/problems/iterator-for-combination/
*/

/*
https://zxi.mytechroad.com/blog/bit/leetcode-1286-iterator-for-combination/

Use a bitmask to represent the chars selected.
start with (2^n – 1), decrease the mask until there are c bit set.
stop when mask reach to 0.

mask: 111 => abc
mask: 110 => ab
mask: 101 => ac
mask: 011 => bc
mask: 000 => “” Done

Time complexity: O(2^n)
Space complexity: O(1)

*/

class CombinationIterator {
  private mask: number;
  private readonly length: number;
  private readonly chars: string[];

  constructor(characters: string, combinationLength: number) {
    this.chars = characters.split("").reverse();
    this.length = combinationLength;
    this.mask = (1 << characters.length) - 1;
  }

  next(): string {
    this.hasNext();
    let ans = "";
    for (let i = this.chars.length - 1; i >= 0; --i) {
      if ((this.mask >> i) & 1) {
        ans += this.chars[i];
      }
    }
    this.mask--;
    return ans;
  }

  hasNext(): boolean {
    while (this.mask >= 0 && this.popcount(this.mask) !== this.length) {
      this.mask--;
    }
    return this.mask > 0;
  }

  private popcount(x: number): number {
    return x.toString(2).split("0").join("").length;
  }
}

class CombinationIterator2 {
  result: string[];
  counter: number;

  constructor(characters: string, combinationLength: number) {
    this.result = [];
    this.counter = 0;

    const helper = (cur: string, characters: string) => {
      if (cur.length >= combinationLength) {
        this.result.push(cur);
        return;
      }

      for (let i = 0; i < characters.length; i++) {
        helper(cur + characters[i], characters.slice(i + 1));
      }
    };

    helper("", characters);
  }

  next(): string {
    this.counter++;
    return this.result[this.counter - 1];
  }

  hasNext(): boolean {
    return !!this.result?.[this.counter];
  }
}
