/*
1431. Kids With the Greatest Number of Candies

Level: Easy

https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
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