/* 
30. Substring with Concatenation of All Words

https://leetcode.com/problems/substring-with-concatenation-of-all-words/

*/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
https://zxi.mytechroad.com/blog/hashtable/leetcode-30-substring-with-concatenation-of-all-words/

Solution1: HashTable + Brute Force
S is length of string
W is length of word list

Time complexity: O((|S| – |W|*l) * |W|*l))
Space complexity: O(|W|*l)
*/
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        if (words.empty() || s.empty())
            return {};

        const int n = words.size();
        const int l = words[0].length();

        if (n * l > s.length())
            return {};

        std::string_view ss(s);

        unordered_map<std::string_view, int> expected;

        for (const string &word : words)
            ++expected[string_view(word)];

        vector<int> ans;

        for (int i = 0; i <= ss.length() - n * l; ++i)
        {
            std::unordered_map<std::string_view, int> seen;
            int count = 0;
            for (int j = 0; j < n; ++j)
            {
                std::string_view w = ss.substr(i + j * l, l);
                auto it = expected.find(w);
                if (it == expected.end())
                    break;
                if (++seen[w] > it->second)
                    break;
                ++count;
            }
            if (count == n)
                ans.push_back(i);
        }
        return ans;
    }
};

/*
 Time O(n ^2) s.length * words.length
    Space O(n)   words.length
   
 */
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        if (words.empty() || s.empty())
            return {};

        const int n = words.size();
        const int l = words[0].length();

        if (n * l > s.length())
            return {};

        vector<int> res;

        unordered_map<string, int> expected;

        for (string str : words)
        {
            expected[str] = expected[str] + 1; // expected[str] is 0 by default
        }

        for (int i = 0; i <= s.size() - n * l; i++)
        {
            unordered_map<string, int> copy(expected);
            int count = n;
            int start = i;
            while (count > 0)
            {
                string word = s.substr(start, l);
                if (!copy.count(word) || copy[word] < 1)
                {
                    // word is not in words list
                    break;
                }
                copy[word]--;
                count--;
                start += l;
            }
            if (count == 0) // all words are matched
                res.push_back(i);
        }

        return res;
    }
};