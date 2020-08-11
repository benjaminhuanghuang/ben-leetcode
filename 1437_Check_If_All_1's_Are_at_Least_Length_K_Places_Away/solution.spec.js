/*
1437. Check If All 1's Are at Least Length K Places Away

Level: Medium

https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away
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