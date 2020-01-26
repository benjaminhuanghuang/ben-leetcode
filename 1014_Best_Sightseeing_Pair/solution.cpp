/*
1014. Best Sightseeing Pair
https://leetcode.com/problems/best-sightseeing-pair/
*/

#include <vector>
#include <numeric>

using namespace std;

/*
https://www.youtube.com/watch?v=CoyAaGEhmFY&feature=youtu.be
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int max_score = 0, pre_max = 0;
        for (auto a : A) {
            max_score = max(max_score, a + pre_max);
            pre_max = max(pre_max, a) - 1;
        }
        return max_score;
    }
};