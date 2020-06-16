/*
1450. Number of Students Doing Homework at a Given Time

Level: Easy

https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time
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