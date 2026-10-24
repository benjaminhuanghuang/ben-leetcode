#include <vector>
#include <string>
#include <climits>

using namespace std;

/*
    go throught the string. 
    use position to record the index of word1 or word2 in the string.
    
*/
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        // find word at position
        // position is index of word1 or word2
        int position = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1 || words[i] == word2) {
                if (position != -1 && words[position] != words[i]) {
                    res = min(res, i - position);
                }
                position = i;
            }
        }
        return res;
    }
};