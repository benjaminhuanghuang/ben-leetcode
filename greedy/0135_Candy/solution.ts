/*
135. Candy

https://leetcode.com/problems/candy/
*/

/*
 give each child at least one candy. 
 Then, for each child, check if the child has a higher rating than 
 the previous child.
*/
function candy(ratings: number[]): number {
  const candies = new Array(ratings.length).fill(0);

  // from left to right
  for (let i = 0; i < ratings.length; i++) {
    if (i > 0 && ratings[i] > ratings[i - 1]) {
      candies[i] = candies[i - 1] + 1;
    } else {
      candies[i] = 1;
    }
  }

  // from right to left
  for (let i = ratings.length - 1; i >= 0; i--) {
    if (i < ratings.length - 1 && ratings[i] > ratings[i + 1]) {
      candies[i] = Math.max(candies[i + 1] + 1, candies[i]);
    }
  }

  return candies.reduce((sum, candy) => sum + candy, 0);
}
