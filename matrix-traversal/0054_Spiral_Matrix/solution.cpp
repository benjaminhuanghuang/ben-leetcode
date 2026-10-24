/*
54. Spiral Matrix

https://leetcode.com/problems/spiral-matrix/
*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0)
            return res;

        int rowStart=0;
        int rowEnd=matrix.size()-1;

        int colStart=0;
        int colEnd = matrix[0].size()-1;


        while(rowStart <= rowEnd && colStart <= colEnd){

            // Left to right
            for (int i = colStart; i <= colEnd; i++) {
                res.push_back(matrix[rowStart][i]);
            }

            // top to bottom
            for (int j = rowStart+1; j <= rowEnd; j++) {
                res.push_back(matrix[j][colEnd]);
            }

            // right to left
            if(rowStart+1 <= rowEnd){
                for (int k = colEnd-1; k >= colStart; k--) {
                    res.push_back(matrix[rowEnd][k]);
                }
            }
            if(colStart+1 <= colEnd){
                for (int k = rowEnd-1; k > rowStart; k--) {
                    res.push_back(matrix[k][colStart]);
                }
            }

            rowStart++;
            rowEnd--;
            colStart++;
            colEnd--;
        }
        return res;
    }
};