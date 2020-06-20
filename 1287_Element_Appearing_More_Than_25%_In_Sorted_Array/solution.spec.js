/*
1287. Element Appearing More Than 25% In Sorted Array

Level: Easy

https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array
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