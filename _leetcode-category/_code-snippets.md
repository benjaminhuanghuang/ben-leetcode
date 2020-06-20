### isPrime
```
  bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    for (int i = 2; i <= sqrt(x); ++i)
      if (x % i == 0) return false;
    return true;
  }
```
### isLeap
```
  bool isLeap(int year)
  {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  }
```