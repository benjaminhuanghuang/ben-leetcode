/*
1503. Last Moment Before All Ants Fall Out of a Plank

Level: Medium

https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank
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