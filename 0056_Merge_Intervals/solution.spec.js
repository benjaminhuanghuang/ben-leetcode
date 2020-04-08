/*
56. Merge Intervals

Level: Nediun

https://leetcode.com/problems/merge-intervals/
*/
import { merge } from './solution';

describe('Solution 0056 test', () => {;
  beforeEach(() => {
    
  });

  it('test case 1', () => {
    const input = [[1,3],[2,6],[8,10],[15,18]]

    expect(merge(input)).toEqual( [[1,6],[8,10],[15,18]]);
  });

  
  it('test case 2', () => {
    const input = [[1,4],[4,5]]

    expect(merge(input)).toEqual([[1,5]]);
  });
});