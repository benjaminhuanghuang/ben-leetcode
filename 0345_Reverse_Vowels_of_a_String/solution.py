'''
345. Reverse Vowels of a String

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".

'''


def is_vowel(c):
    vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
    return c in vowels


def reverse_vowels(str):
    str = list(str)
    start = 0
    end = len(str) - 1
    while start < end:
        if is_vowel(str[start]) and is_vowel(str[end]):
            str[start], str[end] = str[end], str[start]
            start += 1
            end -= 1
        else:
            if not is_vowel(str[start]):
                start += 1

            if not is_vowel(str[end]):
                end -= 1
    return ''.join(str)


str = "hello"

print reverse_vowels(str)

str = "leetcode"

print reverse_vowels(str)