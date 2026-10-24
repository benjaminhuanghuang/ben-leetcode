/*
135. Candy

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

*/
using System;
using System.Linq;

public class Solution135 {
    public int Candy(int[] ratings) {
         var candies = new int[ratings.Length];
        // from left to right
        for (int i = 0; i < ratings.Length; i++)             
        {                 
            if (i > 0 && ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
            else
            {
                candies[i] = 1;
            }
        }

        // from right to left
        for (int i = ratings.Length - 1; i >= 0; i--)
        {
            if (i < ratings.Length - 1 && ratings[i] > ratings[i + 1])
            {
                candies[i] = Math.Max(candies[i + 1] + 1, candies[i]);
            }
        }

        return candies.Sum();
    }
}