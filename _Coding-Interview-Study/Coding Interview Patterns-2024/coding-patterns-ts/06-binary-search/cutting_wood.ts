/*
Determine the highest possible setting of the woodcutter (H) so that it cuts at least k meters of wood,

切割高度越高 → 收集木头越少； 切割高度越低 → 收集木头越多。
这是一个单调递减函数关系，所以可以用二分搜索。
*/
function cuttingWood(heights: number[], k: number): number {
  let left = 0;
  let right = Math.max(...heights);

  while (left < right) {
    // Bias midpoint to the right for upper-bound binary search
    const mid = Math.floor((left + right) / 2) + 1;

    if (cutsEnoughWood(mid, k, heights)) {
      left = mid; // try a higher cut height
    } else {
      right = mid - 1; // cut lower to collect more wood
    }
  }

  return right;
}

// Helper function: check if cutting at height H yields at least k wood
function cutsEnoughWood(H: number, k: number, heights: number[]): boolean {
  let woodCollected = 0;

  for (const height of heights) {
    if (height > H) {
      woodCollected += height - H;
    }
  }

  return woodCollected >= k;
}
/*
Time complexity: The time complexity of cutting_wood is O(n log(m)), where n denotes the number
of trees, and m denotes the maximum height of the trees. This is because we perform a binary
search over the range [0, m]. Each iteration of the binary search calls the cuts_enough_wood function,
which runs in O(n) time. This results in an overall time complexity of O(log(m)) · O(n) =
O(n *log(m)).

Space complexity: The space complexity is 0(1).
·*/
