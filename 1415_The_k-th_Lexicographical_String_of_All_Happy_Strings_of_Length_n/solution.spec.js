/*
1415. The k-th Lexicographical String of All Happy Strings of Length n

Level: Medium

https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
*/
import { twoSum } from './solution';

describe('Solution 0001 test', () => {;
  beforeEach(() => {
    
  });

  it('test case', () => {
    const input = [2, 7, 11, 15]
    const target = 9;
    expect(twoSum(input, target)).toEqual([1,0]);
  });
});