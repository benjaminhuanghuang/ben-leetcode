/*
1452. People Whose List of Favorite Companies Is Not a Subset of Another List

Level: Medium

https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list
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