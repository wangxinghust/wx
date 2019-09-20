# wx
leetcode刷题记录

刷完100题后，有了一定的基础，开始刷Top Interview Questions里的题

---

2019-7-16 21:57:14

除开需要订阅解锁的题目，总算是刷完了Top Interview Question列表里的题目，目前leetcode刷题量194，外加剑指offer 66题，以及各类笔试题目。

---

2019-8-25 22:42:48

刷完了 Top 100 Liked Questions

---

总结一下刷过的所有题目

1. Two Sum  
经典的hash，遍历的同时存入hash数组，可用STL里的unordered_set
2. Add Two Numbers  
两个链表模拟加法，先用l3存储各位相加的值，再去计算进位，进位的过程中判断是否存在next ListNode，不存在则创建val为1的ListNode
3. Longest Substring Without Repeating Characters  
滑动窗口配合set集合，也可以将set改为map，同时存下标，窗口滑动的时候可以一步到位
4. Median of Two Sorted Arrays  
对短的数组进行二分查找或遍历，短数组里的i可推出长数组的下标j，判断是否满足条件即可，长短数组可以在开始判断条件里进行交换，确保第一个数组是长数组
5. Longest Palindromic Substring  
对于回文串，大多是从center出发，同时要注意奇数和偶数回文串的区别，维持两个变量，用于记录最大回文串的左index和右index，返回substr出来的子串即可
6. ZigZag Conversion  
之字形字符串，注意给的字符串和结果字符串位置对应即可
7. Reverse Integer  
记录正负，%运算和*运算，对10 %出来的值，累\*到结果里，着重注意溢出情况  
```cpp
if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < (-8))) return 0;
```
8. String to Integer (atoi)  
前导' '的忽略，符号的记录，以及再次注意上题里的溢出情况
9. Palindrome Number  
题目要求不可以转成string，因此可以考虑类似题7，反转int即可，注意溢出
10. Regular Expression Matching  
字符串的匹配问题，常用思想，dp，关键在于dp公式的推导，以及first_match的引入，用来解决'.'的问题，dp解决'*'的问题  
dp[i][j]=dp[i][j+2]，由推导公式可知从后向前遍历更好
11. Container With Most Water  
双指针，或者说滑动窗口，每次取左右边界较小的值向内收缩，试探是否有更大值得出现，因为area由边界较小的值和ij差值确定，改变这个较小值才会出现新的可能更大的值
12. Integer to Roman  
由于数字范围的限定，可以直接确定所有的状态，遍历即可
```cpp
const int ints[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
const string roman[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
```
13. Roman to Integer  
遇到C,X,I较特殊的罗马字符时，判断随后的字符，满足要求则步进2，否则步进1
14. Longest Common Prefix  
垂直扫描解法，先求字符串组minLen，再一次垂直扫描，即循环判断s1[i]...sn[i]
15. 3Sum  
对于此类问题，先考虑能否排序，也即时间复杂度要求，排序后相对易解  
需要考虑的是注意避免重复，第2个数和第3个数成滑动窗口式收缩查值
16. 3Sum Closest  
相比于上一题，增加的内容是维持一个绝对差值，在遍历的过程中找最小差值即可
17. Letter Combinations of a Phone Number  
可以考虑dp的运用，重点大概在用map来存数字对应的string，遍历相应的string，也可以考虑dfs、bfs，bfs的话需要维持一个queue.size()即可，每次循环内用queue.size()作为for循环终止判断的值
18. 4Sum  
可以考虑在3Sum的基础上再加一层循环，比较方便记忆
19. Remove Nth Node From End of List  
找Nth Node通常是双指针，找到后删除对应节点即可
20. Valid Parentheses  
利用栈即可，考虑'(','[','{'三种符号，可以用stack\<char>存储，取值时判断一下stack.top()是否对应
21. Merge Two Sorted Lists  
注意dummyNode的运用即可，依次比较，注意尾部多余的合并
22. Generate Parentheses  
最好记的方法是利用递归，维持两个变量，open代表'('括号，close代表')'的数量，能否递归的条件是open<max和close小于open,记得写清楚递归终止条件，长度达标则返回  
或者第二种递归，将n拆成三段，1,c,n-c-1三段，那么 ans.push_back("(" + left + ")" + right);  
因此可以再次用dp实现
23. Merge k Sorted Lists  
最好记的方法是利用merge 2 sorted lists
24. Swap Nodes in Pairs  
对于链表，注意断开即可
25. Reverse Nodes in k-Group  
每k个reverse一次，然后每k个重连一下newhead
26. Remove Duplicates from Sorted Array  
双指针解法
27. Remove Element  
依旧双指针即可
28. Implement strStr()  
kmp或其他模式串匹配即可，重点在于next数组
29. Divide Two Integers  
不用*,/,%，讨论区也无特别好的方案，不如直接累减了事
30. Substring with Concatenation of All Words  
暴力求解，利用map来存字符串出现的次数
31. Next Permutation  
stl里有讲，找到第一个小于末尾的数，swap，将其后的数排序即可，由于其后的数成降序排列，因此反转一下即可
32. Longest Valid Parentheses  
字符串匹配首考虑滑动窗口，然后是dp，此题dp较复杂
33. Search in Rotated Sorted Array  
查找问题首选二分查找，注意反转数组里是否允许重复，允许重复的话需对重复情况特殊处理
34. Find First and Last Position of Element in Sorted Array  
依次是二分查找，重点在于对待等于的情况如何处理
35. Search Insert Position  
二分查找，或者直接STL里的lower_bound
36. Valid Sudoku  
暴力求解最好记，判断行列条件是否满足
37. Sudoku Solver  
暴力遍历，可手写check函数，判断该行该列有无遍历的数，没有则可以插入，dfs下去
38. Count and Say  
暴力求解即可，注意string和int的转换即可
39. Combination Sum  
回溯法，再注意数组是排好序的，target判断的时候注意和candidates[i]比较一下
40. Combination Sum II  
在前一题的基础上，手动排序一下
41. First Missing Positive  
开同样大小的hash数组，对于小于等于0的和负数避开即可，再次遍历，有点类似桶排序
42. Trapping Rain Water  
方法较多，单调栈貌似可行，dp的方法是左右max数组，对每一个数，左右max的最小值减去当前高度即可  
单调栈的方法思路是，栈单调递减，遇到大于栈顶的则弹出，直至小于
43. Multiply Strings  
模拟乘法，注意进位
44. Wildcard Matching  
字符串匹配，依旧是dp，从后向前遍历，难点仍是dp公式推导
45. Jump Game II  
dp超时，可用贪心算法，但不太好理解
46. Permutations  
思路在于swap，以及回溯递归
47. Permutations II  
可以用set去重，牺牲性能，或者增加跳过重复的判断
```cpp
if (i != k && num[i] == num[k]) continue;
```
48. Rotate Image  
从外至内，依次翻转，注意各类特殊情况，最内层是奇数还是偶数矩阵，和题54不同
49. Group Anagrams  
总体想法还是基于26大小的hash数组，可以用map来存排好序的string对应未排序的，分好类别
50. Pow(x, n)  
意义不明，区分负数，以及INT_MIN的负数即可
51. N-Queens  
N皇后问题可用回溯法解，每次标记，退出时恢复矩阵
52. N-Queens II  
可以借助题51直接累计求出的结果数，也可以先求出结果数组，推导规律
53. Maximum Subarray  
基于dp求解，dp[i]代表0...i间最大数组和，递推dp[i+1]  
复杂度上还是滑动窗口更优，但要注意滑动窗口left和right不能相遇，否则有得出0的风险
54. Spiral Matrix  
注意最内层的特殊情况，依次有几种考量，可以利用四个变量来控制上下行、左右列，比较清晰明了
55. Jump Game  
题45的简化，返回bool，可用dp，可用贪心
56. Merge Intervals  
先排序，再一次添加到结果里，添加的时候判断一下左右值即可
57. Insert Interval  
先找插入的位置，头尾及中间，然后更新，插入更新值，删除这个区间的值
58. Length of Last Word  
查找末尾第一个非空格，以及末尾第一个空格即可
59. Spiral Matrix II  
按螺旋遍历的同时赋值即可，方阵的遍历较为简单
60. Permutation Sequence  
根据规律求解，利用阶乘数组来求，维护一个数组，存所有可以选择的数，由阶乘的算法去取数
61. Rotate List  
遍历到倒数第k+1个节点，注意k极大情况下需要使用%，双指针找到需要调整的位置即可，注意判断一下是否刚好回到头结点
62. Unique Paths  
dp求解即可
63. Unique Paths II  
依旧是dp求解，考虑障碍物paths为0即可
64. Minimum Path Sum  
仍然是dp
65. Valid Number  
各种极限条件的考察
66. Plus One  
设置一个进位标志bool carry即可，根据标志来判断是否继续循环即可，以及头部插入1
67. Add Binary  
二进制加法模拟，先判断长短串，做一个交换，然后用switch判断三种状态即可
68. Text Justification  
区分清楚各个情况
69. Sqrt(x)  
二分查找，找第一个刚好小于等于的数
70. Climbing Stairs  
斐波拉契数列，递归or dp
71. Simplify Path  
利用find_first_not_of和find_first_of来模拟split函数，最后判断一下字符串是否为空，为空补"/"即可
72. Edit Distance  
增删改即三种情况，可以转换为dp
73. Set Matrix Zeroes  
每行遍历的时候，标记此行是否有0存在，遇0的同时，将其纵向的一个标记数组置为true
74. Search a 2D Matrix  
当做一维数组来处理 matrix[mid / col][mid % col]，然后运用二分查找
75. Sort Colors  
计数排序，进阶是双指针，维持左右指针的位置，往中间进行交换
76. Minimum Window Substring  
本质还是滑动窗口，formed变量的运用是个小技巧，==递增，<递减，以及两个map，一个存匹配串，一个存窗口内的值
77. Combinations  
回溯法，回溯的过程不太好写，总的来说就是终止条件，回溯递归
78. Subsets  
与上题类似，可以用回溯来解
79. Word Search  
dfs或bfs，现在感觉bfs比dfs还好写点，用queue比用递归舒服
80. Remove Duplicates from Sorted Array II  
双指针即可
81. Search in Rotated Sorted Array II  
二分查找，确定是在哪片区域，mid和right均大于，则需要left++步进来跨越最高点
82. Remove Duplicates from Sorted List II  
基于双指针改进
83. Remove Duplicates from Sorted List  
基于双指针，若重复，则删除该节点即可
84. Largest Rectangle in Histogram  
比较简单的dp方法是对每一个i，往左查和往右查，得到right[i]-left[i]，再次遍历得最大面积
85. Maximal Rectangle  
转化为题84，继续计算