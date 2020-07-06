#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <numeric>
using namespace std;

void fill(vector<vector<char>> &output , int startCol, char fanchy, char c){
    for(int row = 0; row< 5; row++)
    {
        for(int col = startCol; col< startCol+5; col++)
        {
          if((col -startCol) == abs(2-row) || (startCol+ 4 - col ) == abs(2-row))
          {
              output[row][col] = fanchy;
          }
          else
          {
              output[row][col] = '.';
          }
        }
    }
    output[2][startCol+2] = c;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
   char input[15];
    cin >> input;
    int len = strlen(input);
    
    int rows = 5;
    int cols = 4 *len+1;
    vector<vector<char>> output(rows, vector<char>(cols));
    
    for(int i=0; i < len; i++)
    {
      if((i+1)%3 !=0)
      {
        fill(output, i * 4,'#',input[i]);
          
      }
    }
    
    for(int i=0; i < len; i++)
    {
      if((i+1)%3 ==0)
      {
         fill(output, i * 4,'*',input[i]);
      }
    }
    
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++)
        {
            cout << output[r][c];
        }
        cout<<endl;
    }
    return 0;
}