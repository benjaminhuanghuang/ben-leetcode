/*
1103. Distribute Candies to People

https://leetcode.com/problems/distribute-candies-to-people/
 */

#include <vector>

using namespace std;
/*
    My Solution
 */
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int round = 0;
        while(candies >0)
        {
            for(int i =0 ;i < num_people; i++)
            {
                int c = round * num_people + i + 1;
                if(candies > c)
                {
                    candies -= c;
                    ans[i] += c;
                }
                else
                {
                    ans[i] += candies;
                    candies = 0;
                    break;
                }
            }
            round++;
        }
        return ans;
    }
};