## Reference
- [Solution: Reservoir sampling](https://en.wikipedia.org/wiki/Reservoir_sampling)
- [Rejection Sampling]()
## Code snippets
```
  #include<ctime> 
  #include<random> 


  // Use current time as seed for random generator 
  srand(time(0));

  // 
  randNum = rand() % 10;       // [0 - 9]
  randNum = rand() % 10 + 1;   // [1 - 10]
  randNum = rand() % (max - min + 1) ) + min;   // [min, max]
  
  int j = rand() % (n - i) + i;      // [i, n)
  
  // generates a floating-point random number between 0 (inclusive) and 1.0 (exclusive).
  rand() / (RAND_MAX + 1.0) 
  
```

## Random problems
- 382. Linked List Random Node
- 384. Shuffle an Array
- 398. Random Pick Index
- 470. Implement Rand10() Using Rand7()
- 478. Generate Random Point in a Circle
- 497. Random Point in Non-overlapping Rectangles