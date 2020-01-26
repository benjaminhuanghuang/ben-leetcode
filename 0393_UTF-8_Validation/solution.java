package cn.huang.leetcode;
/*
393. UTF-8 Validation

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

    For 1-byte character, the first bit is a 0, followed by its unicode code.
    For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.

This is how the UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

Example 1:

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.

Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.

 */


/*
对于UTF-8编码中的任意字节B，如果B的第一位为0，则B独立的表示一个字符(ASCII码)；
如果B的第一位为1，第二位为0，则B为一个多字节字符中的一个字节(非ASCII字符)；
如果B的前两位为1，第三位为0，则B为两个字节表示的字符中的第一个字节；
如果B的前三位为1，第四位为0，则B为三个字节表示的字符中的第一个字节；
如果B的前四位为1，第五位为0，则B为四个字节表示的字符中的第一个字节；
因此，对UTF-8编码中的任意字节，根据第一位，可判断是否为ASCII字符；根据前二位，可判断该字节是否为一个字符编码的第一个字节；
根据前四位（如果前两位均为1），可确定该字节为字符编码的第一个字节，并且可判断对应的字符由几个字节表示；根据前五位（如果前四位为1），
可判断编码是否有错误或数据传输过程中是否有错误。

那么根据上面的描述，我们可以先来判断第一位，如果是0的话，则说明是ASCII码，我们直接跳过，判断方法是只要比二进制数10000000小的数第一
位肯定是0，然后我们来处理第一位是1的情况，由于第一位的1只是个标识符，后面连续跟的1的个数才是表示后面的字节的个数，我们可以统一
从第一位开始连续1的个数，然后减去1就是后面的字节的个数，我想的办法是如果该数字大于等于128，则表示第一位是1，然后减去128，如果得到的数大
于等于64，则表示第二位是1，依次类推就可以得到连续的个数，我们要注意10000000这个数是不合法的，遇到了直接返回false。我们得到了cnt的个数，
只要验证后面的字节是否是以10开头的数即可，验证方法也很简单，只要这个数在10000000 ~ 10111111范围之间，则一定是10开头的，

 masks = [0x0, 0x80, 0xE0, 0xF0, 0xF8]
 bits = [0x0, 0x0, 0xC0, 0xE0, 0xF0]
 */
public class LC_0393_UTF8Validation {
    public boolean validUtf8(int[] data) {
        int i = 0;
        int count = 0;
        while (i < data.length) {
            int v = data[i];
            if (count == 0) {
                if ((v & 240) == 240 && (v & 248) == 240) {
                    count = 3;
                } else if (((v & 224) == 224) && (v & 240) == 224) {
                    count = 2;
                } else if ((v & 192) == 192 && (v & 224) == 192) {
                    count = 1;
                } else if ((v | 127) == 127) {
                    count = 0;
                } else {
                    return false;
                }
            } else {
                if ((v & 128) == 128 && (v & 192) == 128) {
                    count--;
                } else {
                    return false;
                }
            }

            i++;
        }

        return count == 0;
    }

    public static boolean validUtf8_2(int[] data) {
        return validUtf8(data, 0);
    }

    public static boolean validUtf8(int[] data, int start) {
        if (start == data.length) return true;
        int byteLen = data[start] >> 4;
        if (byteLen <= 7) return validUtf8(data, start + 1);//以0开头的
        if (byteLen == 12 || byteLen == 13) byteLen = 2;//数据格式为110x
        else if (byteLen == 14) byteLen = 3;//以1110开头的
        else if (byteLen == 15) byteLen = 4;//以1111开头的
        else return false;//数据格式为10xx的
        if (byteLen + start > data.length) return false;
        for (int i = 1; i < byteLen; i++) {
            if (data[start + i] > 0xbf || data[start + i] < 0x80) //二进制是否 begin with 10
                return false;
        }
        return validUtf8(data, start + byteLen);
    }
}
