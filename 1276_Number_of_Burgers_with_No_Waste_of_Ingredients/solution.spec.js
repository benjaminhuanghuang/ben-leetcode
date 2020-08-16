/*
1276. Number of Burgers with No Waste of Ingredients

Level: Medium

https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients
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