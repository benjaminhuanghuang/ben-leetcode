package cn.huang.leetcode;

import java.util.HashSet;

public class LC_0929_UniqueEmailAddresses {
    public int numUniqueEmails(String[] emails) {
        if(emails == null) return 0;

        HashSet<String> emailSet = new HashSet<>();

        for(int i =0;i < emails.length; i++)
        {
            String email = emails[i];

            String[] parts = email.split("@");

            String userName = parts[0];
            String domainName = parts[1];

            int indexOfPlus = userName.indexOf('+');
            if (indexOfPlus > 0);
                userName = userName.substring(0, indexOfPlus);

            parts = userName.split(".");
            userName = String.join("", parts);

            emailSet.add(userName + "@" + domainName);
        }
        return emailSet.size();
    }
}
