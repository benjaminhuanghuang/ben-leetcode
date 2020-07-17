


- multiplication

- addition

- abs()
最小值取abs会overflow!
```
  int num = abs(-2147483648)  // overflow!

  // Fixed
  long num = abs(-2147483648)
```

- long to int
```
  int num = abs(2147483648)  // overflow! get -2147483647
```


## Problems
- 29. Divide Two Integers