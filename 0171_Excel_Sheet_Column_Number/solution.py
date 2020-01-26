'''
171. Excel Sheet Column Number
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
'''


def title_to_number(title):
    result = 0
    for char in title:
        result = result * 26 + ((ord(char) - ord('A') + 1))

    return result


def col_title_to_num(title="LW"):
    '''
    index from 0
    :param title:
    :return:
    '''
    base = ord('A')
    result = 0
    for i in xrange(len(title)):
        result = (ord(title[i]) - base + 1) + result * 26
    return result - 1
