/*
1337. The K Weakest Rows in a Matrix

Level: Easy

https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix
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