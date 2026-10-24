public class Solution393
{
    public bool ValidUtf8(int[] data)
    {
        // 0, 10000000, 11100000, 11110000, 11111000
        var masks = new int[] { 0x0, 0x80, 0xE0, 0xF0, 0xF8 };
        //  0 ,  0  ,  11000000, 11100000, 11110000
        var bits = new int[] { 0x0, 0x0, 0xC0, 0xE0, 0xF0 };

        int index = 0;
        int len = data.Length;

        while (index < data.Length)
        {
            int codeLength = 4;
            while (codeLength >= 0)
            {
                if ((data[index] & masks[codeLength]) == bits[codeLength])
                    break;
                codeLength--;
            }
            if (codeLength == 0 || codeLength + index > len)
                return false;

            for (int i = 1; i < codeLength; ++i)
            {
                if ((data[i + index] & 0xC0) != 0x80)   // 0xC0=11000000  0x80=10000000
                    return false;
            }
            index += codeLength;
        }
        return true;
    }
}

/*
var s = new Solution393();
var data = new int[] {248, 130, 130, 130};  //11111000, 10000010, 10000010, 10000010
Console.WriteLine(s.ValidUtf8(data));

 */
