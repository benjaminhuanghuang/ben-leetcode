/*
558. Logical OR of Two Binary Grids Represented as Quad-Trees

Level: Medium

https://leetcode.com/problems/logical-or-of-two-binary-grids-represented-as-quad-trees
*/
package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;
/*
  Solution: 
*/
/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {}

    public Node(boolean _val,boolean _isLeaf,Node _topLeft,Node _topRight,Node _bottomLeft,Node _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    public Node intersect(Node quadTree1, Node quadTree2) {
        if (!quadTree1 && !quadTree2)
            return nullptr;
        if (!quadTree2)
            return quadTree1;
        if (!quadTree1)
            return quadTree2;

        if (quadTree1 -> isLeaf && quadTree1 -> val)
            return quadTree1;
        if (quadTree2 -> isLeaf && quadTree2 -> val)
            return quadTree2;
        if (quadTree1 -> isLeaf && !quadTree1 -> val)
            return quadTree2;
        if (quadTree1 -> isLeaf && !quadTree1 -> val)
            return quadTree1;

        auto tl = intersect(quadTree1 -> topLeft, quadTree2 -> topLeft);
        auto tr = intersect(quadTree1 -> topRight, quadTree2 -> topRight);
        auto bl = intersect(quadTree1 -> bottomLeft, quadTree2 -> bottomLeft);
        auto br = intersect(quadTree1 -> bottomRight, quadTree2 -> bottomRight);

        if (tl -> val == tr -> val && tl -> val == bl -> val
                && tl -> val == br -> val && tl -> isLeaf && tr -> isLeaf && bl -> isLeaf && br -> isLeaf) {
            return new Node(tr -> val, true, NULL, NULL, NULL, NULL);
        } else {
            return new Node(false, false, tl, tr, bl, br);
        }
    }
}