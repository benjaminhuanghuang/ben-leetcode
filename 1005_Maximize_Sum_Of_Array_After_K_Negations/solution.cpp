/*
1005. Maximize Sum Of Array After K Negations

Level: Easy

https://leetcode.com/problems/maximize-sum-of-array-after-k-negations
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <numeric>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  Solution: 
    1. 如果有负数， 那肯定是优先做负数， 而且是从最小的负数开始操作（绝对值最大的）
    2. 如果负数操作的次数已经到K了， 那么就当前的操作就已经是最后的结果了
    3. 如果从负数开始操作到0， 那么，剩下最好的操作一定是对0进行不停的操作直到K， 因为如果去操作正数的话会导致结果变小
    4. 如果没有0， 只有正数了，还剩下x次要操作， 那么这时候有两种情况，
    如果x是偶数，那么，sum保持当前状态不变，因为可以对同一个数做偶数次操作，相当于没有操作。
    如果x是奇数，那么，我们要做一次操作，sum会变小，这时候，应该选绝对值最小的数， 然后剩下做偶数次操作，sum不变。

*/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int sum = accumulate(A.begin(), A.end(), 0);

        int count = 0;
        int minabs = abs(A[0]);
        for(int num: A) {
            minabs = min(minabs, abs(num));
            if(num < 0) {
                sum += 2 * abs(num);
                count++;
                if(count >= K) {
                    break;
                }
            }
            else if(num == 0) {
                break;
            }
            else {
                int remain = K-count;
                if(remain%2 == 1) {
                    sum -= 2 * minabs;
                }
                break;
            }
        }
        return sum;
    }
};