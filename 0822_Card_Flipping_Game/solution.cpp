/*
822. Card Flipping Game

Level: Medium

https://leetcode.com/problems/card-flipping-game
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  https://www.cnblogs.com/grandyang/p/10163255.html
  给了一些正反都有正数的卡片，可以翻面，让我们找到一个最小的数字，在卡的背面，且要求其他卡正面上均没有这个数字。
  简而言之，就是要在backs数组找一个最小数字，使其不在fronts数组中。
  
  既然不能在fronts数组中，说明卡片背面的数字肯定跟其正面的数字不相同，否则翻来翻去都是相同的数字，
  肯定会在fronts数组中。那么我们可以先把正反数字相同的卡片都找出来，将数字放入一个HashSet，
  也方便我们后面的快速查找。现在其实我们只需要在其他的数字中找到一个最小值即可，
  因为正反数字不同，就算fronts中其他卡片的正面还有这个最小值，我们可以将那张卡片翻面，
  使得相同的数字到backs数组，总能使得fronts数组不包含有这个最小值，就像题目中给的例子一样，
  数字2在第二张卡的背面，就算其他卡面也有数字2，只要其不是正反都是2，我们都可以将2翻到背面去，
  Solution: 
*/

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
       int res = INT_MAX, n = fronts.size();
        unordered_set<int> same;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) same.insert(fronts[i]);
        }
        for (int front : fronts) {
            if (!same.count(front)) res = min(res, front);
        }
        for (int back : backs) {
            if (!same.count(back)) res = min(res, back);
        }
        return (res == INT_MAX) ? 0 : res;  
    }
};