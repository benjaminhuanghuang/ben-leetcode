/*
1275. Find Winner on a Tic Tac Toe Game

Level: Easy

https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game
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