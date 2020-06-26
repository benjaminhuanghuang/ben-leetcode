/*
806. Number of Lines To Write String

Level: Easy

https://leetcode.com/problems/number-of-lines-to-write-string
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  Solution: 
*/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int>result{0,0};
        int space = 0;
        for (int i = 0; i < S.size(); i++) {
            int charWidth = widths[S[i] - 'a'];
            if (100 - space >= charWidth ) {
                space += charWidth;
            } else {
                // add new line
                result[0] += 1;
                space = charWidth;
            }

        }
        result[0]++;
        result[1] = space;
        return result;
    }
};