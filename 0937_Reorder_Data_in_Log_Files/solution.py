'''
937. Reorder Log Files

'''
class Solution:
    '''
    # https://blog.csdn.net/fuxuemingzhu/article/details/83961188
    首先需要进行分割成索引和内容，
    然后对内容的第一个单词进行判断，如果是英文字符串，那么把内容和索引构成tuple放到letters的列表里；
    如果是数字字符串，那么直接把当前的这个log放到nums列表里。
    然后对letter logs进行排序，因为tuple里首先是内容，然后是索引，所以会先对内容进行排序，然后再对索引进行排序。
    把letters排序的结果重置成正常的状态和nums拼接在一起，返回。
    '''
    def reorderLogFiles(self, logs):
        letters = []
        nums = []
        for log in logs:
            logsplit = log.split(" ")
            if logsplit[1].isalpha():
                letters.append((" ".join(logsplit[1:]), logsplit[0]))
            else:
                nums.append(log)
        letters.sort()
        return [letter[1] + " " + letter[0] for letter in letters] + nums
