package cn.huang.leetcode;

import java.util.Arrays;

/*
    475. Heaters
    design a standard heater with fixed warm radius to warm all the houses.

    Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so
    that all houses could be covered by those heaters.

    So, your input will be the positions of houses and heaters seperately, and your expected output will be the
    minimum radius standard of heaters.

    Note:
    Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
    Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
    As long as a house is in the heaters' warm radius range, it can be warmed.
    All the heaters follow your radius standard and the warm radius will the same.
 */
public class LC_0475_Heaters {
    //每一个house的位置，binary search离它最近的两边的heater，然后取距离小的那个更新结果。
    public int findRadius(int[] houses, int[] heaters) {
        // sort
        Arrays.sort(heaters);

        int radius = 0;
        for (int house : houses) {
            int local = binarySearch(heaters, house);
            radius = Math.max(radius, local);
        }

        return radius;
    }

    private int binarySearch(int[] heaters, int house) {
        int l = 0, r = heaters.length - 1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (heaters[mid] == house) return 0;
            else if (heaters[mid] < house) l = mid;
            else r = mid;
        }
        return Math.min(Math.abs(house - heaters[l]), Math.abs(house - heaters[r]));
    }

    //https://www.youtube.com/watch?v=NaSxg2Qi-_w
    public int findRadius2(int[] houses, int[] heaters) {
        // sort
        Arrays.sort(heaters);

        int maxDicst = Integer.MIN_VALUE;
        for (int i = 0; i < houses.length; i++) {
            int lowDist = Integer.MAX_VALUE;
            int highDist = Integer.MAX_VALUE;
            int currHouse = houses[i];
            //Find out where this current house would be placed in the heaters array
            //returns index of the search key, if it is contained in the array, else it returns (-(insertion point) - 1).
            int index = Arrays.binarySearch(heaters, currHouse);
            if (index < 0)
                index = (index + 1) * -1;    //
            if (index >= 1)
                lowDist = currHouse - heaters[index-1];
            if (index < heaters.length)
                highDist = heaters[index] - currHouse;
            maxDicst = Math.max(maxDicst, Math.min(lowDist, highDist));
        }
        return maxDicst;
    }
    /*
    https://leetcode-cn.com/problems/heaters/solution/475-gong-nuan-qi-by-en-zhao/
    */
    public int findRadius_v3(int[] houses, int[] heaters) {
        Arrays.sort(houses);
     Arrays.sort(heaters);
 
     int j = 0;
     int max = -1;
     for(int i = 0;i < houses.length;i++){
         if((j + 1 < heaters.length) && (Math.abs(houses[i] - heaters[j]) >= Math.abs(houses[i] - heaters[j + 1]))){
             j++;
             i--; // i 保持不变
         }else{
             if(max < Math.abs(houses[i] - heaters[j])){
                 max = Math.abs(houses[i] - heaters[j]);
             }
         }
     }
     return max;
     }
}
