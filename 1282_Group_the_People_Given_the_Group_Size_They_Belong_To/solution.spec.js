/*
1282. Group the People Given the Group Size They Belong To

Level: Medium

https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to
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