using System.Collections.Generic;

public class Queue {
    private Stack<int> stackIn = new Stack<int>();
    private Stack<int> stackOut = new Stack<int>();
    
    // Push element x to the back of queue.
    public void Push(int x) {
        stackIn.Push(x);
    }

    // Removes the element from front of queue.
    public void Pop() {
        if(stackOut.Count == 0)
        {
            while(stackIn.Count > 0)
            {
                stackOut.Push(stackIn.Pop());
            }
        }
        stackOut.Pop();
    }

    // Get the front element.
    public int Peek() {
        if(stackOut.Count == 0)
        {
            while(stackIn.Count > 0)
            {
                stackOut.Push(stackIn.Pop());
            }
        }
        return stackOut.Peek();
    }

    // Return whether the queue is empty.
    public bool Empty() {
        return (stackIn.Count ==0 && stackOut.Count==0);
    }
}