/*
1277. Count Square Submatrices with All Ones

Level: Medium

https://leetcode.com/problems/count-square-submatrices-with-all-ones
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