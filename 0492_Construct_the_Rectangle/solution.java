package cn.huang.leetcode;

/*
492. Construct the Rectangle

For a web developer, it is very important to know how to design a web page's size. So, given a specific rectangular web
page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:

 */
public class LC_0492_ConstructtheRectangle {
    public int[] constructRectangle(int area) {
        int root = (int) Math.sqrt(area);
        while(area%root !=0){
            root --;
        }
        // return W,L, L >= W
        return new int[]{area/root, root};
    }
}
