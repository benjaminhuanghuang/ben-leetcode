/*
767. Reorganize String
https://leetcode.com/problems/reorganize-string/
*/


#include <string>
#include <vector>

using namespace std;
  /*
  首先找出字符数量最大的字符，如果大于S长度的一半，返回空字符串，
  如果小于，则将该字符从索引0开始，间隔着放置(0, 2, 4...)。然后再放其他字符，

  如果偶数索引没有放完，则接着间隔着放，如果偶数索引结束了，则从索引1开始(1, 3, 5...)。
  */
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> ch(26);
        int maxChar = 0;
        for(char c: S) {
            ch[c - 'a'] ++;
            if(ch[c-'a'] > ch[maxChar])
                maxChar = c - 'a';
        }

        int len = S.length();
        if(len < 2 * ch[maxChar] - 1)
            return "";

        // put maxChar
        int index = 0;
        vector<char> res(len);
        for(int i = 0 ; i < ch[maxChar]; i++) {
            res[index] = (char)(maxChar + 'a');
            index += 2;
        }
        ch[maxChar] = 0;
        // put other chars
        for(int i = 0 ; i < 26; i++) {
            int count = ch[i];
            while(count > 0 ) {
                if(index >= len ) index = 1;
                res[index] = (char)(i + 'a');
                index += 2;
                count --;
            }
        }

        return string(res.begin(), res.end());
    }
};