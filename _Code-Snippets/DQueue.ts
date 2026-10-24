/*
Using a JavaScript array as a queue involves utilizing the push and shift methods. 

Push and Pop:
    push(): Adds an element to the end of the array.
    pop(): Removes and returns the last element of the array.

Unshift and Shift:
    unshift(): Adds an element to the beginning of the array.
    shift(): Removes and returns the first element of the array.

*/

// Create an empty array to use as a deque
const deque = [];

// Add elements to the end (push)
deque.push(1);
deque.push(2);

console.log(deque); // Output: [1, 2]

// Add elements to the front (unshift)
deque.unshift(0);
console.log(deque); // Output: [0, 1, 2]

// Remove elements from the front (shift)
const frontElement = deque.shift();
console.log(frontElement); // Output: 0
console.log(deque); // Output: [1, 2]

// Remove elements from the end (pop)
const lastElement = deque.pop();
console.log(lastElement); // Output: 2
console.log(deque); // Output: [1]
