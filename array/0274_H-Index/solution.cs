using System;

public class Solution274 {
    public int HIndex(int[] citations) {
        Array.Sort(citations);
        int h = 0;
        for(int i = 0; i < citations.Length; i++){
            // 得到当前的H指数
            // 引用数citations[i]，大于该引用数文献的数量是citations.length - i
            int currH = Math.Min(citations[i], citations.Length - i);
            if(currH > h){
                h = currH;
            }
        }
        return h;
    }
     //https://segmentfault.com/a/1190000003794831
     public int hIndex(int[] citations) {
        int[] stats = new int[citations.Length + 1];
        int n = citations.Length;
        // 统计各个引用次数对应多少篇文章
        for(int i = 0; i < n; i++){
            stats[citations[i] <= n ? citations[i] : n] += 1;
        }
        int sum = 0;
        // 找出最大的H指数
        for(int i = n; i > 0; i--){
            // 引用大于等于i次的文章数量，等于引用大于等于i+1次的文章数量，加上引用等于i次的文章数量 
            sum += stats[i];
            // 如果引用大于等于i次的文章数量，大于引用次数i，说明是H指数
            if(sum >= i){
                return i;
            }
        }
        return 0;
    }
}