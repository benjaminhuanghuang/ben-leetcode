/*
406. Queue Reconstruction by Height

Level: Medium

https://leetcode.com/problems/queue-reconstruction-by-height
*/
#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  Solution: 
  队列中的每个元素是一个 pair，分别为身高和前面身高不低于当前身高的人的个数，persion[0]
  
  让我们重新排列队列，使得每个 pair 的第二个参数都满足题意。
  然后新建一个空的数组，遍历之前排好序的数组，然后根据每个元素的第二个数字，将其插入到 res 数组中对应的位置，

*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //给队列先排个序，按照身高高的排前面，如果身高相同，则第二个数小的排前面。
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> res;
        for (auto a : people) {
            res.insert(res.begin() + a[1], a);
        }
        return res;
    }
};
/*
https://www.cnblogs.com/grandyang/p/5928417.html
No extra space
*/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        for (int i = 0; i < people.size(); i++) {
            auto p = people[i];
            if (p[1] != i) {
                people.erase(people.begin() + i);
                people.insert(people.begin() + p[1], p);
            }
        }
        return people;
    }
};


/*
https://www.cnblogs.com/grandyang/p/5928417.html
No extra space
*/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        for (int i = 1; i < people.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < i; ++j) {
                if (cnt == people[i][1]) {
                    auto t = people[i];
                    for (int k = i - 1; k >= j; --k) {
                        people[k + 1] = people[k];
                    }
                    people[j] = t;
                    break;
                }
                ++cnt;
            }
        }
        return people;
    }
};