/*
406. Queue Reconstruction by Height

Level: Medium

https://leetcode.com/problems/queue-reconstruction-by-height
*/
import { reconstructQueue } from './solution';

describe('Solution 0406 test', () => {;
  beforeEach(() => {
    
  });

  it('test case', () => {
    const input = [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
    const ans = [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]];
    expect(reconstructQueue(input)).toEqual(ans);
  });
});