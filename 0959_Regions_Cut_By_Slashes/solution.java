package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*

959. Regions Cut By Slashes
In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.



Example 1:

Input:
[
  " /",
  "/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:

Example 2:

Input:
[
  " /",
  "  "
]
Output: 1
Explanation: The 2x2 grid is as follows:

Example 3:

Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:

Example 4:

Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:

Example 5:

Input:
[
  "//",
  "/ "
]
Output: 3
Explanation: The 2x2 grid is as follows:



Note:

1 <= grid.length == grid[0].length <= 30
grid[i][j] is either '/', '\', or ' '.

 */
public class LC_0959_RegionsCutBySlashes {
    /*
    https://lequ7.com/2018/12/30/richang/leetcode-jiang-jie-959-Regions-Cut-By-Slashes/
     */
    public int regionsBySlashes(String[] grid) {
        int result = 0;
        int index = -1;
        List<DisJointSet> list = new ArrayList<>();
        for (String s : grid) {
            for (Character c : s.toCharArray()) {
                for (int i = 0; i < 4; i++) {
                    DisJointSet ds = new DisJointSet();
                    list.add(ds);
                }
            }
        }
        for (int j = 0; j < grid.length; j++) {
            for (int i = 0; i < grid[j].length(); i++) {
                DisJointSet ds1 = list.get(++index);
                DisJointSet ds2 = list.get(++index);
                DisJointSet ds3 = list.get(++index);
                DisJointSet ds4 = list.get(++index);
                System.out.println(grid[j].charAt(i));
                if (grid[j].charAt(i) ==' '){
                    DisJointSet.union(ds1, ds2);
                    DisJointSet.union(ds2, ds3);
                    DisJointSet.union(ds3, ds4);
                }
                if (grid[j].charAt(i) =='/'){
                    DisJointSet.union(ds1, ds4);
                    DisJointSet.union(ds2, ds3);
                }
                if (grid[j].charAt(i) =='\\'){
                    DisJointSet.union(ds1, ds2);
                    DisJointSet.union(ds3, ds4);
                }
                if (i < grid[j].length() - 1) {
                    DisJointSet.union(ds2, list.get(index + 4));
                }
                if (j < grid.length - 1) {
                    DisJointSet.union(ds3, list.get(index + 4 * (grid[j].length() - 1) + 1));
                }
            }
        }
        for (DisJointSet ds : list) {
            if (ds.find() == ds) {
                result++;
            }
        }
        return result;
    }
}

class DisJointSet {
    public DisJointSet parent;
    public int rank;

    public DisJointSet() {
        rank = 0;
        parent = this;
    }

    public DisJointSet find() {
        if (parent != this) {
            parent = parent.find();
        }
        return parent;
    }

    public static void union(DisJointSet ds1, DisJointSet ds2) {
        DisJointSet ds1Root = ds1.find();
        DisJointSet ds2Root = ds2.find();
        if (ds1Root != ds2Root) {
            if (ds1Root.rank > ds2Root.rank) {
                ds2Root.parent = ds1Root;
            } else if (ds1Root.rank < ds2Root.rank) {
                ds1Root.parent = ds2Root;
            } else if (ds1Root.rank == ds2Root.rank) {
                ds1Root.parent = ds2Root;
                ds2Root.rank++;
            }
        }
    }
}
