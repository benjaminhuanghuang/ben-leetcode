/*
982. Triples with Bitwise AND Equal To Zero

Level: Hard

https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero
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