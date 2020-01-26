package cn.huang.leetcode;
/*
195. Tenth Line
 */
public class LC_0195_TenthLine {
    /*
方法一：

awk 'NR==10' file.txt  //awk的默认动作就是打印$0，所以NR==10后面可以不用加{print $0}

方法二：

sed -n '10p' file.txt  //如果不够10行，则什么也不打印

方法三：

line=$(cat file.txt | wc -l)     //千万注意，等号前后一定不要有空格 if [ "$line" -ge 10 ] ; then   //$line的双引号也可以不用加   cat file.txt | head -n 10 | tail -n 1  fi

     */
}
