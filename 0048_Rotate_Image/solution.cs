/*
48. Rotate Image


You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?


*/

public class Solution048 {
    // Rotate the matrix layer by layer
    public void Rotate(int[,] matrix) {
        int n = matrix.GetLength(0);
        int layerNum = n / 2;
        for (int layer = 0; layer < layerNum; layer++)
        {
            int first = layer;
            int last = n- 1 - layer;
            for(int i = first; i < last; i++)
            {
                int offset = i - first;
                int temp = matrix[first, i ]; // back the up layer
                // left to up
                matrix[first, i] = matrix[last - offset, first];
                // bottom to left
                matrix[last - offset, first] = matrix[last, last - offset];
                // right to bottom
                matrix[last, last - offset] = matrix[i, last];
                // up to right
                matrix[i, last] = temp;                              
            }
        }
    }        
}