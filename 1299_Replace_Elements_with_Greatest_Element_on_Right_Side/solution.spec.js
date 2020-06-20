/*
1299. Replace Elements with Greatest Element on Right Side

Level: Easy

https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side
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