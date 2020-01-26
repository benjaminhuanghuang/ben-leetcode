package cn.huang.leetcode;

import java.util.*;

/*
    811. Subdomain Visit Count
 */
public class LC_0811_SubdomainVisitCount {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> res = new ArrayList<>();
        HashMap<String, Integer> dic = new HashMap<>();
        for (int i = 0; i < cpdomains.length; i++) {
            String[] parts = cpdomains[i].split(" ");
            int count = Integer.parseInt(parts[0]);
            String domain =parts[1];

            String[] domainParts = domain.split("\\.");
            for(int j = domainParts.length -1; j >=0 ;j --)
            {
                String[] subParts = Arrays.copyOfRange(domainParts, j , domainParts.length);
                String subDomain = String.join( ".", subParts);

                if(dic.containsKey(subDomain))
                {
                    dic.put(subDomain, dic.get(subDomain) + count);
                }
                else
                {
                    dic.put(subDomain, count);
                }
            }

        }
        for (Map.Entry<String, Integer> entry : dic.entrySet()) {
           res.add(entry.getValue() + " "+ entry.getKey());
        }

        return res;
    }
}