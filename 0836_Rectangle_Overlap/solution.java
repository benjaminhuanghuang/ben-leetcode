package cn.huang.leetcode;

/*
 836	Rectangle Overlap
 */
public class LC_0836_RectangleOverlap {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int left_1 = rec1[0];
        int bottom_1 = rec1[1];
        int right_1 = rec1[2];
        int top_1 = rec1[3];

        int left_2 = rec2[0];
        int bottom_2 = rec2[1];
        int right_2 = rec2[2];
        int top_2 = rec2[3];

        return !(top_2 <= bottom_1 ||
                bottom_2 >= top_1 ||
                right_2 <= left_1 ||
                left_2 >= right_1);

    }
}
