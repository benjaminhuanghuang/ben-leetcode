/*
1371. Find the Longest Substring Containing Vowels in Even Counts

Level: Medium

https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts
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