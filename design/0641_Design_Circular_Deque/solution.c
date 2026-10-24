/*
641. Design Circular Deque

Level: Medium

https://leetcode.com/problems/design-circular-deque
*/


/*
  Solution: 
*/



typedef struct {
    
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
    
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
  
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
  
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
  
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
  
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
  
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
  
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
  
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
  
}

void myCircularDequeFree(MyCircularDeque* obj) {
    
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/