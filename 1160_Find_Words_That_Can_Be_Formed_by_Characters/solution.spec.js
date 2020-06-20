/*
1160. Find Words That Can Be Formed by Characters

Level: Easy

https://leetcode.com/problems/find-words-that-can-be-formed-by-characters
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