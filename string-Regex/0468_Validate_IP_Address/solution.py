class Solution(object):
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        if self.validIPV4(IP):
            return 'IPv4'
        if self.validIPV6(IP):
            return 'IPv6'
        return 'Neither'

    def validIPV4(self, IP):
        parts = IP.split('.')
        if len(parts) != 4:
            return False
        for part in parts:
            if not part:
                return False
            if not part.isdigit():
                return False
            if part[0] == '0' and len(part) > 1:
                return False
            if int(part) > 255:
                return False
        return True

    def validIPV6(self, IP):
        parts = IP.split(':')
        if len(parts) != 8:
            return False
        for part in parts:
            if not part:
                return False
            if len(part) > 4:
                return False
            for ch in part:
                # if (ch < '0' and ch > '9') or (ch < 'a' or ch > 'f') or (ch < 'A' or ch > 'F'):
                if not ((ch >= '0' and ch <= '9') or (ch >= 'a' and ch <= 'f') or (ch >= 'A' and ch <= 'F')):
                    return False

        return True


s = Solution()
print s.validIPV6("2001:0db8:85a3:0:0:8A2E:0370:7334")
print s.validIPV6("20EE:FGb8:85a3:0:0:8A2E:0370:7334")
