/*
1072. Flip Columns For Maximum Number of Equal Rows

Level: Medium

https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows
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