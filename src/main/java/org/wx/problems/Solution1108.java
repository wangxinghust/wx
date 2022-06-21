package org.wx.problems;

public class Solution1108 {
    //正则
    public String defangIPaddr(String address) {
        return address.replaceAll("\\.", "[.]");
    }

    //直接替换
    public String defangIPaddr2(String address) {
        return address.replace(".", "[.]");
    }
}
