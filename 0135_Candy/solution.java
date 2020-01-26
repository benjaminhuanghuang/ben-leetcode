package cn.huang.leetcode;

import java.util.Arrays;

/*
135. Candy

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.


 */
public class LC_0135_Candy {
    /*
        First pass: left to right, the right one will have one more candy than the left one if taller.

        Second pass: right to left, the left one will be at least one more candy than the right one if taller.


        Time Complexity: O(n) Space Complexity: O(n)
     */
    public int candy(int[] ratings) {
        int A[] = new int[ratings.length];
        // 每人至少一个糖果
        Arrays.fill(A, 1);

        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1])
                A[i] = A[i - 1] + 1;
        }

        int sum = A[ratings.length - 1];
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && A[i] <= A[i + 1])
                // 要比邻居多,并求与邻居相比的取较大值
                A[i] = A[i + 1] + 1;
            sum += A[i];
        }
        return sum;
    }
}
