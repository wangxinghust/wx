package org.wx.problems;

import java.util.Arrays;

public class Solution0929 {
    public int numUniqueEmails(String[] emails) {
        long cnt = Arrays.stream(emails).map(str -> {
            int indexOfAt = str.indexOf('@');
            String localName = str.substring(0, indexOfAt);
            String domainName = str.substring(indexOfAt + 1);
            int indexOfPlus = localName.indexOf('+');
            if (indexOfPlus >= 0) {
                localName = localName.substring(0, indexOfPlus);
            }
            localName = localName.replaceAll("\\.", "");
            System.out.println(localName + '@' + domainName);
            return localName + '@' + domainName;
        }).distinct().count();
        return (int) cnt;
    }
}
