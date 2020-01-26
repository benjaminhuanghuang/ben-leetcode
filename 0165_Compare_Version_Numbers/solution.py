'''
165. Compare Version Numbers


Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of
the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37


'''


class Solution_my(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1_arr = version1.split(".")
        v2_arr = version2.split(".")
        i = 0

        while i < max(len(v1_arr), len(v2_arr)):
            v1 = int(v1_arr[i]) if i < len(v1_arr) else 0
            v2 = int(v2_arr[i]) if i < len(v2_arr) else 0
            if v1 < v2:
                return -1
            elif v1 > v2:
                return 1
            i += 1
        return 0


class Solution(object):
    # Can not pass test case "0.0.1"
    def compareVersion_lazy(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        float1 = float(version1)
        float2 = float(version2)

        if float1 > float2:
            return 1
        elif float1 < float2:
            return -1
        else:
            return 0

    # did not pass "1" "1.1"
    def compareVersion_naive(self, version1, version2):

        list1 = version1.split('.')
        list2 = version2.split('.')
        len1 = len(list1)
        len2 = len(list2)
        i1 = i2 = 0

        while i1 < len1 and i2 < len2:
            if int(list1[i1]) > int(list2[i2]):
                return 1
            elif int(list1[i1]) < int(list2[i2]):
                return -1
            else:
                i1 += 1
                i2 += 1

        return 0

    def compareVersion(self, version1, version2):

        list1 = version1.split('.')
        list2 = version2.split('.')
        len1 = len(list1)
        len2 = len(list2)
        i1 = i2 = 0

        while i1 < len1 or i2 < len2:
            if i1 < len1:
                v1 = int(list1[i1])
            else:
                v1 = 0

            if i2 < len2:
                v2 = int(list2[i2])
            else:
                v2 = 0

            if v1 > v2:
                return 1
            elif v1 < v2:
                return -1
            else:
                i1 += 1
                i2 += 1

        return 0


v1 = "13.27.23"
v1 = "13.29"
v2 = "13.28.25"

s = Solution()
print s.compareVersion(v1, v2)
