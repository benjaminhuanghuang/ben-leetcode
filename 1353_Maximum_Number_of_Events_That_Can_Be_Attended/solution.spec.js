/*
1353. Maximum Number of Events That Can Be Attended

Level: Medium

https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended
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