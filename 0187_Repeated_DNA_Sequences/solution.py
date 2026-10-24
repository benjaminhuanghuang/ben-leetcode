class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        pool = set()
        res = set()

        for i in range(len(s) - 9):
            dna = s[i: i + 10]
            if dna not in pool:
                pool.add(dna)
            else:
                res.add(dna)

        return list(res)
