package cn.huang.leetcode;
/*
    193. Valid Phone Numbers

    Given a text file file.txt that contains list of phone numbers (one per line), write a one liner bash script
    to print all valid phone numbers.

    You may assume that a valid phone number must appear in one of the following two formats:
    (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)

    You may also assume each line in the text file must not contain leading or trailing white spaces.


 */
public class LC_0193_ValidPhoneNumbers {

    /*


awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt


sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt

grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt

     */
}
