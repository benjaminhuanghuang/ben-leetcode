/*
1432. Max Difference You Can Get From Changing an Integer

Level: Medium

https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer
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