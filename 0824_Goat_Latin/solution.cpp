/*
824. Goat Latin

https://leetcode.com/problems/goat-latin/
*/
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
  string toGoatLatin(string S)
  {
    const string vowls = "aeiouAEIOU";
    string ans;
    string word;
    int index = 0;
    istringstream s(S);
    while (s >> word)
    {
      if (vowls.find(word[0]) == string::npos)
        word = word.substr(1) + word[0];
      ans += " " + word + "ma" + string(++index, 'a');
    }
    return ans.substr(1);
  }
};

class Solution
{
public:
  string toGoatLatin(string S)
  {
    const string vowls = "aeiouAEIOU";
    string ma = "ma";
    bool wordFound = false;
    string result =""; 
    string temp = "";
    for(int i = 0; i < S.size(); i++){
        
        if( S[i] != ' ' ){
            temp+= S.substr(i,1);
            wordFound = true;
        }
        
        if( (S[i] == ' ' || i == S.size()-1 ) && wordFound){
            wordFound = false;
            
            if(vowls.find(temp[0]) != string::npos){
                temp+= temp.substr(0,1);
                temp.erase(0,1);
            }
            
            ma+="a";
            
            result+= (temp + ma + " ");
            temp = "";
        }
        
    }
    
    if( result[result.size()-1] == ' '){
        result.erase(result.size()-1,1);
    }
    return result;
  }
};