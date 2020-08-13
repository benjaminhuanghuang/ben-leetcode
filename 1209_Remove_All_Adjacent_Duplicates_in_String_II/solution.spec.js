/*
1209. Remove All Adjacent Duplicates in String II

Level: Medium

https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii
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