/*
    Using Array as a Stack
    arrays have built-in methods that align well with stack operation
*/

// Create an empty array to use as a stack
const stack = [];

// Push elements onto the stack
stack.push(1);
stack.push(2);
stack.push(3);

console.log(stack); // Output: [1, 2, 3]

// Peek at the top element of the stack without removing it
const peek = stack[stack.length - 1];
console.log(peek); // Output: 3

// Pop elements from the stack
const poppedElement1 = stack.pop();
console.log(poppedElement1); // Output: 3
console.log(stack); // Output: [1, 2]

const poppedElement2 = stack.pop();
console.log(poppedElement2); // Output: 2
console.log(stack); // Output: [1]

// Add peek method to Array prototype
/*
Array.prototype.peek = function () {
    if (this.length === 0) {
        return undefined; // or throw an error, depending on your requirements
    }
    return this[this.length - 1];
};
*/
