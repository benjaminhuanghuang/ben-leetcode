package cn.huang.leetcode;

/*
	832	 Flipping an Image
 */
public class LC_0832_FlippingAnImage {
    public int[][] flipAndInvertImage(int[][] A) {
        for(int r=0; r<A.length; r++ )
        {
            int left =0 ;
            int right = A[0].length-1;

            while(left <= right) {  // make sure to invert all of the bits
                int v = A[r][left];
                A[r][left] = A[r][right] ^ 1;
                A[r][right] = v ^ 1;
                left++;
                right--;
            }
        }
        return A;
    }
}
