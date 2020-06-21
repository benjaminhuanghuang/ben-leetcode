# 193. Valid Phone Numbers

# https://leetcode.com/problems/valid-phone-numbers



# Solution
# https://www.cnblogs.com/grandyang/p/5389375.html

awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt 


sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt


grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt

