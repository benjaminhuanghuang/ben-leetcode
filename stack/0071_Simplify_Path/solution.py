'''
71. Simplify Path

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

'''


class Solution(object):
    def simplifyPath_my(self, path):
        """
        :type path: str
        :rtype: str
        """
        dir_list = path.split("/")

        result = []
        for i in xrange(len(dir_list)):
            if dir_list[i] == "" or dir_list[i] == ".":
                continue
            if dir_list[i] == "..":
                if len(result) > 0:
                    result.pop()
            else:
                result.append(dir_list[i])
        return "/" + "/".join(result)


s = Solution()
# print s.simplifyPath_my("/..")
print s.simplifyPath_my("/a/./b/../../c/")
