using System;
using System.Linq;
using System.Collections.Generic;

public class Solution084 {
    public int LargestRectangleArea(int[] heights) {
        var maxArea = 0;
        var mystack = new Stack<int>();

        for (var i = 0; i < heights.Length; i++)             
        {                 
            while (mystack.Count > 0 && heights[i] <= heights[mystack.Peek()])
            {
                var top = mystack.Pop();
                var prelessHeight = mystack.Count == 0 ? -1 : mystack.Peek();

                maxArea = Math.Max(maxArea, heights[top]*(i - prelessHeight - 1));
            }

            mystack.Push(i);
        }

        var lastIndex = mystack.Any() ? mystack.Peek() : -1;
        while (mystack.Any())
        {
            var top = mystack.Pop();
            var prelessHeight = mystack.Count == 0 ? -1 : mystack.Peek();

            maxArea = Math.Max(maxArea, heights[top] * (lastIndex - prelessHeight));
        }

        return maxArea;
    }

    //栈来存放非递减的height序列, 即碰到大于等于栈顶的就入栈, 碰到小于栈顶的就pop。
    //对于每个pop出的元素h[stack[top]]，都要计算以它为最低高度的矩形的面积, 高度就是h[stack[top]], 
    //宽度就是i － stack[-1] - 1, 注意栈中的元素都是非递减的。在h末尾多加一个0的目的是保证栈中的元素都可以被pop出    
}