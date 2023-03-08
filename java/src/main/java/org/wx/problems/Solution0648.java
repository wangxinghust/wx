package org.wx.problems;

import java.util.*;

/**
 * 648. 单词替换
 */
public class Solution0648 {
    public String replaceWords(List<String> dictionary, String sentence) {
        Collections.sort(dictionary, (str1, str2) -> {
            return str1.length() - str2.length();
        });
        String[] split = sentence.split(" ");
        for (int i = 0; i < split.length; i++) {
            for (int j = 0; j < dictionary.size(); j++) {
                if (split[i].length() >= dictionary.get(j).length() && split[i].substring(0, dictionary.get(j).length()).equals(dictionary.get(j))) {
                    split[i] = dictionary.get(j);
                    break;
                }
            }
        }
        return String.join(" ", split);
    }

    // 方法一：哈希集合
    public String replaceWords2(List<String> dictionary, String sentence) {
        Set<String> dictionarySet = new HashSet<String>();
        for (String root : dictionary) {
            dictionarySet.add(root);
        }
        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            for (int j = 0; j < word.length(); j++) {
                if (dictionarySet.contains(word.substring(0, 1 + j))) {
                    words[i] = word.substring(0, 1 + j);
                    break;
                }
            }
        }
        return String.join(" ", words);
    }

    //方法二：字典树
    public String replaceWords3(List<String> dictionary, String sentence) {
        Trie trie = new Trie();
        for (String word : dictionary) {
            Trie cur = trie;
            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                cur.children.putIfAbsent(c, new Trie());
                cur = cur.children.get(c);
            }
            cur.children.put('#', new Trie());
        }
        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; i++) {
            words[i] = findRoot(words[i], trie);
        }
        return String.join(" ", words);
    }

    public String findRoot(String word, Trie trie) {
        StringBuffer root = new StringBuffer();
        Trie cur = trie;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (cur.children.containsKey('#')) {
                return root.toString();
            }
            if (!cur.children.containsKey(c)) {
                return word;
            }
            root.append(c);
            cur = cur.children.get(c);
        }
        return root.toString();
    }

    class Trie {
        Map<Character, Trie> children;

        public Trie() {
            children = new HashMap<Character, Trie>();
        }
    }
}
