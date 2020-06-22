/*
263. Ugly Number

Level: Easy

https://leetcode.com/problems/ugly-number
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
    bool isUgly(int num) {
        if (num <= 0)
        return false;

    if (num == 1)
        return true;

    while (num % 2 == 0)
        num /= 2;

    while (num % 3 == 0)
        num /= 3;

    while (num % 5 == 0)
        num /= 5;

    return num == 1;
    }
};