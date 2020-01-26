/*
1065. Index Pairs of a String

https://leetcode.com/problems/index-pairs-of-a-string/

Given a text string and words (a list of strings), return all index pairs [i, j] so that the substring 
text[i]...text[j] is in the list of words.

Example 1:

Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]
Example 2:

Input: text = "ababa", words = ["aba","ab"]
Output: [[0,1],[0,2],[2,3],[2,4]]
Explanation:
Notice that matches can overlap, see "aba" is found in [0,2] and [2,4].

*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        
    }
};