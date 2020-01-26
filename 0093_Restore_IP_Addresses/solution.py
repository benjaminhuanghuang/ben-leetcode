'''
93. Restore IP Addresses

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

'''


class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """

        def dfs(s, sub, ips, ip):
            if sub == 4:  # should be 4 parts
                if s == '':
                    ips.append(ip[1:])  # remove first '.'
                return
            for i in range(1, 4):  # the three ifs' order cannot be changed!
                if i <= len(s):  # if i > len(s), s[:i] will make false!!!!
                    if int(s[:i]) <= 255:
                        dfs(s[i:], sub + 1, ips, ip + '.' + s[:i])
                    if s[0] == '0':
                        break  # make sure that res just can be '0.0.0.0' and remove like '00'

        ips = []
        dfs(s, 0, ips, '')
        return ips

    def restoreIP_brutal_force(self, s):
        result = []
        for one in xrange(1, 4):
            for two in xrange(one + 1, one + 4):
                if two > len(s) - 1:
                    continue
                for thr in xrange(two + 1, two + 4):
                    if thr > len(s) - 1:
                        continue

                    s1 = s[0:one]
                    s2 = s[one: two]
                    s3 = s[two: thr]
                    s4 = s[thr:]
                    if (self.is_valid(s1) and self.is_valid(s2) and self.is_valid(s3) and self.is_valid(s4)):
                        ip = s1 + "." + s2 + "." + s3 + "." + s4
                        result.append(ip)
        return result

    def is_valid(self, s):
        if s[0] == '0' and len(s) > 1:
            return False
        if len(s) == 3:
            return int(s) <= 255
        if len(s) > 3:
            return False
        return True


s = Solution()
# print s.restoreIP_brutal_force("25525511135")
print s.restoreIP_brutal_force("1111")
