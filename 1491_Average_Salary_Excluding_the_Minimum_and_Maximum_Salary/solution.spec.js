/*
1491. Average Salary Excluding the Minimum and Maximum Salary

Level: Easy

https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary
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