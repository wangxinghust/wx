package org.wx.problems;

import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class Solution0535 {
    // 方法一：id自增
    public class Codec {

        private Map<Integer, String> dataBase = new HashMap<Integer, String>();
        private int id;

        public String encode(String longUrl) {
            id++;
            dataBase.put(id, longUrl);
            return "http://tinyurl.com/" + id;
        }

        public String decode(String shortUrl) {
            int p = shortUrl.lastIndexOf('/') + 1;
            int key = Integer.parseInt(shortUrl.substring(p));
            return dataBase.get(key);
        }
    }

    //方法二：哈希
    public class Codec2 {
        static final int K1 = 1117;
        static final int K2 = 1000000007;
        private Map<Integer, String> dataBase = new HashMap<Integer, String>();
        private Map<String, Integer> urlToKey = new HashMap<String, Integer>();

        public String encode(String longUrl) {
            if (urlToKey.containsKey(longUrl)) {
                return "http://tinyurl.com/" + urlToKey.get(longUrl);
            }
            int key = 0;
            long base = 1;
            for (int i = 0; i < longUrl.length(); i++) {
                char c = longUrl.charAt(i);
                key = (int) ((key + (long) c * base) % K2);
                base = (base * K1) % K2;
            }
            while (dataBase.containsKey(key)) {
                key = (key + 1) % K2;
            }
            dataBase.put(key, longUrl);
            urlToKey.put(longUrl, key);
            return "http://tinyurl.com/" + key;
        }

        public String decode(String shortUrl) {
            int p = shortUrl.lastIndexOf('/') + 1;
            int key = Integer.parseInt(shortUrl.substring(p));
            return dataBase.get(key);
        }
    }

    //方法三：随机生成
    public class Codec3 {
        private Map<Integer, String> dataBase = new HashMap<Integer, String>();
        private Random random = new Random();

        public String encode(String longUrl) {
            int key;
            while (true) {
                key = random.nextInt();
                if (!dataBase.containsKey(key)) {
                    break;
                }
            }
            dataBase.put(key, longUrl);
            return "http://tinyurl.com/" + key;
        }

        public String decode(String shortUrl) {
            int p = shortUrl.lastIndexOf('/') + 1;
            int key = Integer.parseInt(shortUrl.substring(p));
            return dataBase.get(key);
        }
    }

    //方法四：AES对称加密
}
