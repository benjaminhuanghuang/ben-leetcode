# Sliding window

Key words: sub-array, sub-string
Move right pointer, then check the condition, then move the left pointer
Use Hash set as a sliding window
Sum of sub-array with length K

## Complexity

## Template

```js
function slidingWindowFixed(input, windowSize) {
    var ans = window = input[0..windowSize);
    for (var right = windowSize; right < input.length; ++right) {
        const left = right - windowSize;
        remove input[left] from window
        append input[right] to window
        ans = optimal(ans, window);
    }
    return ans;
}


function slidingWindowFlexibleLongest(input) {
    initialize window, ans
    var left = 0;
    for (var right = 0; right < input.length; ++right) {
        append input[right] to window
        while (invalid(window)) {
            remove input[left] from window
            ++left;
        }
        ans = Math.max(ans, window);       // window is guaranteed to be valid here
    }
    return ans;
}

function slidingWindowFlexibleShortest(input) {
    initialize window, ans
    var left = 0;
    for (var right = 0; right < input.length; ++right) {
        append input[right] to window
        while (valid(window)) {
            ans = Math.min(ans, window);   // window is guaranteed to be valid here
            remove input[left] from window
            ++left;
        }
    }
    return ans;
}

```

## Leetcode list

209. Minimum Size Subarray Sum

210. Contains Duplicate II

211. Maximum Sum of Distinct Subarrays With Length K
