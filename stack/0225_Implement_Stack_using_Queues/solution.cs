/*
225. Implement Stack using Queues

*/

using System.Collections.Generic;

public class Stack {
    private Queue<int> myQueue = new Queue<int>(); 
    // Push element x onto stack.
    public void Push(int x)
    {
        myQueue.Enqueue(x);
        for (int i = 1; i < myQueue.Count; i++)
        {
            myQueue.Enqueue(myQueue.Dequeue());
        }
    }

    // Removes the element on top of the stack.
    public void Pop()
    {
        myQueue.Dequeue();
    }

    // Get the top element.
    public int Top()
    {
        return myQueue.Peek();
    }

    // Return whether the stack is empty.
    public bool Empty()
    {
        return myQueue.Count == 0;
    }
}