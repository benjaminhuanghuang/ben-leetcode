/*
242. Valid Anagram

Level: Easy

https://leetcode.com/problems/valid-anagram
*/
import { isAnagram } from './solution';

describe('Solution 242 test', () => {;
  beforeEach(() => {
    
  });

  it('test case 1', () => {
    const input1 = "a"
    const input2 = "ab";
    expect(isAnagram(input1, input2)).toEqual(false);
  });

  it('test case 2', () => {
    const input1 = "a"
    const input2 = "b";
    expect(isAnagram(input1, input2)).toEqual(false);
  });
});