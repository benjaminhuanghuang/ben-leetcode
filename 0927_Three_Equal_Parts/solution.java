package cn.huang.leetcode;

/*
927. Three Equal Parts

Given an array A of 0s and 1s, divide the array into 3 non-empty parts such that all of these parts represent
the same binary value.

If it is possible, return any [i, j] with i+1 < j, such that:

    A[0], A[1], ..., A[i] is the first part;
    A[i+1], A[i+2], ..., A[j-1] is the second part, and
    A[j], A[j+1], ..., A[A.length - 1] is the third part.
    All three parts have equal binary value.

If it is not possible, return [-1, -1].

Note that the entire part is used when considering what binary value it represents.  For example, [1,1,0]
represents 6 in decimal, not 3.  Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.



Example 1:

Input: [1,0,1,0,1]
Output: [0,3]

Example 2:

Input: [1,1,0,1,1]
Output: [-1,-1]



Note:

    3 <= A.length <= 30000
    A[i] == 0 or A[i] == 1



 */
public class LC_0927_ThreeEqualParts {
    /*
    Key obseration is that three parts much have same number and pattern of 1s except the leading part.
    idea is to:

    count how many ones (if num%3!=0 return [-1,-1])
    search from right side to left, until we found num/3 1s. This index is not final answer, but it defines patten of 1s
    from left, ignore leading 0s, and then match the pattern found in step 2, to get the first EndIndex
    do another matching to found second EndIndex

     */
    public int[] threeEqualParts(int[] A) {
        int numOne = 0;
        for (int i : A) {
            if (i == 1) numOne++;
        }

        int[] noRes = {-1, -1};
        if (numOne == 0)
            return new int[]{0, 2};
        if (numOne % 3 != 0)
            return noRes;

        //find index of starting 1 of third string
        int idxThird = 0;
        int temp = 0;
        for (int i = A.length - 1; i >= 0; i--) {
            if (A[i] == 1) {
                temp++;
                if (temp == numOne / 3) {
                    idxThird = i;
                    break;
                }
            }
        }

        int res1 = findEndIdx(A, 0, idxThird);
        if (res1 < 0) return noRes;

        int res2 = findEndIdx(A, res1 + 1, idxThird);
        if (res2 < 0) return noRes;

        return new int[]{res1, res2 + 1};
    }

    //right is the pattern to compare to.
    //return EndIdx of left pattern that matches right side.
    private int findEndIdx(int[] A, int left, int right) {
        while (A[left] == 0)
            left++;
        while (right < A.length) {
            if (A[left] != A[right])
                return -1;
            left++;
            right++;
        }
        return left - 1;
    }
}
