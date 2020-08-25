/*
1560. Most Visited Sector in  a Circular Track

Level: Easy

https://leetcode.com/problems/most-visited-sector-in-a-circular-track
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