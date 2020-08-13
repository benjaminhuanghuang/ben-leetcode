/*
947. Most Stones Removed with Same Row or Column

Level: Medium

https://leetcode.com/problems/most-stones-removed-with-same-row-or-column
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