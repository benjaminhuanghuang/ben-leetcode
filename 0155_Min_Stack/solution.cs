/*
155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
using System;
using System.Collections.Generic;

public class MinStack {
    private Stack<int> valStack;
    private Stack<int> minStack;
    
    public MinStack() {
       this.valStack = new Stack<int>();
       this.minStack = new Stack<int>(); 
    }
    
    public void push(int x) {
        this.valStack.Push(x);
        if(this.minStack.Count ==0 || x <= this.minStack.Peek())
        {
            this.minStack.Push(x);
        }
    }
    
    public void pop() {
        int top = this.valStack.Pop();
        if (top == this.minStack.Peek())
            this.minStack.Pop();
    }
    
    public int top() {
        return this.valStack.Peek();
    }
    
    public int getMin() {
        return this.minStack.Peek();
    }
}
// Easier to understand
public class MinStack2 {
    private Stack<int> valStack;
    private Stack<int> minStack;
    
    public MinStack2() {
       this.valStack = new Stack<int>();
       this.minStack = new Stack<int>(); 
    }
    
    public void push(int x) {
        this.valStack.Push(x);
        if(this.minStack.Count ==0)
        {
            this.minStack.Push(x);
        }
        else
        {
            int min = Math.Min(x, this.minStack.Peek());
            this.minStack.Push(min);
        }
    }
    
    public void pop() {
        this.valStack.Pop();
        this.minStack.Pop();
    }
    
    public int top() {
        return this.valStack.Peek();
    }
    
    public int getMin() {
        return this.minStack.Peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */