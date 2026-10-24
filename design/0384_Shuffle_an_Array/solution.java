package cn.huang.leetcode;

import java.util.Arrays;
import java.util.Random;

/*
384. Shuffle an Array

Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();

 */
public class LC_0384_ShuffleanArray {

    class Solution {

        int[] original;
        int[] shuffled;
        Random r;

        public Solution(int[] nums) {
            original = nums;
            shuffled = Arrays.copyOf(nums, nums.length);
            r = new Random();
        }

        /**
         * Resets the array to its original configuration and return it.
         */
        public int[] reset() {
            shuffled = Arrays.copyOf(original, original.length);
            return shuffled;
        }

        /**
         * Returns a random shuffling of the array.
         */
        public int[] shuffle() {
            int len = shuffled.length;

            for (int i = 0; i < len; i++) {
                int si = r.nextInt(len - i);
                int temp = shuffled[i];
                shuffled[i] = shuffled[si + i];
                shuffled[si + i] = temp;
            }

            return shuffled;
        }
    }
}
