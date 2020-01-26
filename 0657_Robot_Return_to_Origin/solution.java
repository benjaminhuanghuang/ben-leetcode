package cn.huang.leetcode;

/*
    657. Robot Return to Origin

 */
public class LC_0657_RobotReturntoOrigin {
    public boolean judgeCircle(String moves) {
        int vert = 0;
        int horz = 0;
        for (char c : moves.toCharArray()) {
            if (c == 'U')
                vert += 1;
            else if (c == 'D')
                vert -= 1;
            else if (c == 'L')
                horz -= 1;
            else
                horz += 1;

        }
        return vert == 0 && horz == 0;
    }
}
