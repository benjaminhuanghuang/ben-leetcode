# Kadane' Algorithm

Kadane's Algorithm is an efficient algorithm to find the maximum sum of a contiguous subarray within a one-dimensional numeric array.

It operates in O(n) time complexity, making it highly efficient for this problem.

Here’s a step-by-step explanation of Kadane's Algorithm:

- Initialization:

Initialize two variables: `maxEndingHere` and `maxSoFar`.
Set both to the first element of the array.

- Iterate through the array:

For each element in the array (starting from the second element):
Update maxEndingHere to be the maximum of the current element alone or the current element added to maxEndingHere.
Update maxSoFar to be the maximum of maxSoFar and maxEndingHere.

- Return the result:

maxSoFar will hold the maximum sum of a contiguous subarray.
