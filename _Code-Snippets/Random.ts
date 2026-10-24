// Random index in the array
// pseudo-random number between [0, 1)
let list = [1, 2, 3, 4, 5];
const v = list[Math.floor(Math.random() * list.length)];

// [0, 1)
console.log(Math.random());
// 0 to 9
let randomInt = Math.floor(Math.random() * 10);

// 1 to 10
randomInt = Math.floor(Math.random() * 10) + 1;
randomInt = Math.floor(Math.random() * (10 + 1));

// N to M
const N = 20;
const M = 30;
randomInt = Math.floor(Math.random() * (M - N + 1)) + N;
