/*
1365. How Many Numbers Are Smaller Than the Current Number

Level: Easy

https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number
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