def is_happy_num(n):
    numSet = set()
    while True:
        numSet.add(n)
        n = sum([int(x) * int(x) for x in str(n)])
        if n == 1 or n in numSet:
            break
    return n == 1


def isHappy(n):
    numSet = set()
    while n != 1 and n not in numSet:
        numSet.add(n)
        sum = 0
        while n:
            digit = n % 10
            sum += digit * digit
            n /= 10
        n = sum
    return n == 1


print is_happy_num(1111111)
