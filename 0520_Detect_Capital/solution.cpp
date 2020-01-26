/*
520. Detect Capital
https://leetcode.com/problems/detect-capital/
*/
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool detectCapitalUse(string word) {
        string lower = word;
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower); 
    
        if (lower==word) {
            return true;
        }

        string upper=word;
        transform(upper.begin(), upper.end(), upper.begin(), ::toupper); 
        if (upper==word) {
            return true;
        }

        string str = word.substr(1);
        return str == lower.substr(1);
    }
};
/*
https://zxi.mytechroad.com/blog/leetcode/leetcode-520-detect-capital/
*/
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = std::count_if(word.begin(), word.end(), ::isupper);
        return n == 0 || (n == 1 && isupper(word[0])) || n == word.length();
    }
};