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
86. Partition List  
维护三个指针，first、last、cur，遍历时，first指针指向小于x的最后一个节点，last指针指向大于等于x的最后一个节点，也就是上一节点  
当前节点满足小于x，且前一节点大于等于x时，移动至first后，更新first。同时注意newhead(dummyhead)的使用，值设为INT_MIN
87. Scramble String  
二叉树的大多数问题可以通过递归来解决，递归相对简单，此题里面还要注意hash数组的运用，对于字母，只需要开26大小的数组即可，然后就是暴力遍历，对每一个i都试探一遍即可
88. Merge Sorted Array  
从后往前遍历即可，注意第二次遍历将未遍历完的nums2数组copy到nums1数组里去  
89. Gray Code  
递归和bitset的运用，递归不太好理解，类二叉树
90. Subsets II  
totalset，初始化放入一个{}，注意排序的使用，三层循环，第一层循环数组，同时统计相同的count，第二层循环，遍历totalset，循环终止为totalset.size()，第三层循环，遍历相同数个数count，从1到count个，依次添加到totalset中
91. Decode Ways  
动态规划，注意'0'的避免，以及(s[i] == '2' && s[i + 1] <= '6')，从后向前遍历，可以优化之常量存储
92. Reverse Linked List II  
部分节点反转，定位和反转写好即可
93. Restore IP Addresses  
回溯法，试探解，关键是各类判断条件
94. Binary Tree Inorder Traversal  
二叉树中序非递归遍历
95. Unique Binary Search Trees II  
由前面已经计算的出来的状态推后面的，也即动态规划，三层循环，第一层遍历给的数字n，第二层遍历原有的res数组，对res数组里的每个树都进行一遍操作，两种选择，新来的节点作root，或者将新来的节点插入某个右子树节点处  
第三层循环里即遍历所有右节点，备份原右子树，插入新节点，将原右子树插入新节点左子树即可。注意clone函数的使用，自写clone，然后就是每次插入右节点后，还需进行恢复操作，否则会重复插入新来的节点
96. Unique Binary Search Trees  
dp求解，注意公式推导，或者说，对每个节点而言，左子树种类数*右子树种类数即可，累计求和
97. Interleaving String  
2D动态规划可解，注意dp[i][j]代表的意思即可，代表着s1串i长和s2串j长能组成s3串i+j长与否，可优化
98. Validate Binary Search Tree  
递归求解即可，或者利用中序遍历，遍历的时候观察是否排好序即可
99. Recover Binary Search Tree  
中序遍历，找两个不在对应位置的，但是要注意在相邻位置的两个节点，第一次遍历到的时候，将first->next赋值给second即可
100. Same Tree  
递归最简单，非递归的话，用层历比较简单，层历的同时check一下，check函数判断两节点是否同时存在或同时不存在，然后层历添加即可
101. Symmetric Tree  
递归判断，或者改进层历，同时左层历和右层历，进行比较即可
102. Binary Tree Level Order Traversal  
层历
103. Binary Tree Zigzag Level Order Traversal  
双栈存储，或者判断奇数层or偶数层，存入数组的时候下标选用不同即可 int index = leftToRight ? i : size - 1 - i;
104. Maximum Depth of Binary Tree  
递归求解or层历
105. Construct Binary Tree from Preorder and Inorder Traversal  
递归解法最好，同时利用stl里的find函数最好
106. Construct Binary Tree from Inorder and Postorder Traversal  
依旧递归解法，注意helper函数的运用，而不是在原函数上递归
107. Binary Tree Level Order Traversal II  
使用一个level值，对ans[level]进行push_back即可，需先计算depth，也可以在常规层历的基础上，将结果反转
108. Convert Sorted Array to Binary Search Tree  
递归即可
109. Convert Sorted List to Binary Search Tree  
链表找中，记得断开链表，也可以转换为数组，即108题
110. Balanced Binary Tree  
常规递归解，or引入-1，当不满足条件时，返回-1，层层退出这个-1值
111. Minimum Depth of Binary Tree  
递归解即可，仅判断条件和depth求解有所差别
112. Path Sum  
root到某一节点，递归求解即可
113. Path Sum II  
依旧是递归求解，记得pop_back来恢复原状态，毕竟vector\<int>& path
114. Flatten Binary Tree to Linked List  
将右子树搬移至左子树的最右节点处即可，再将左子树搬去右边，记得重置原左子树
115. Distinct Subsequences  
字符串匹配必备之dp，关键还是dp过程推导  
where mem[i+1][j+1] means that S[0..j] contains T[0..i] that many times as distinct subsequences
```cpp
if (t[i] == s[j]) {
    mem[i + 1][j + 1] = mem[i][j] + mem[i + 1][j];
} else {
    mem[i + 1][j + 1] = mem[i + 1][j];
}
```
116. Populating Next Right Pointers in Each Node  
因为是完全二叉树，因此不用考虑right是否存在，直接在当前层对下一层进行修改即可，递增为p=p->next
117. Populating Next Right Pointers in Each Node II  
不是完全二叉树了，维持一个size变量，进行层历即可
118. Pascal's Triangle  
正常dp即可，三角形可转换一下，当成直角三角形处理，而不是等腰三角
119. Pascal's Triangle II  
依旧dp处理，只是改为一维数组即可
120. Triangle  
依旧是dp算法
121. Best Time to Buy and Sell Stock  
依旧是dp，dp[i]表示目前最小，再反向求一波即可，又或者优化为常量，求解min的同时，求解max
122. Best Time to Buy and Sell Stock II  
统计所有的上升对差值的和  
123. Best Time to Buy and Sell Stock III  
可以继续用dp，先算依次操作的，用dp[i]表示i点之后依次操作最大值，然后暴力遍历即可，也即在暴力求解的结果上加上第二次的操作值  
又或者用四个变量来计算，维护hold1,hold2=INT_MIN,release1,realease2=0;然后一次循环即可。
124. Binary Tree Maximum Path Sum  
常规递归解，或者在递归的过程中即维护最大值，注意maxToRoot函数的运用
125. Valid Palindrome  
两端遍历的时候注意过滤即可，isalnum()的运用
126. Word Ladder II  
bfs的运用，也即queue的运用，queue中存paths，需要wordSet来保存剩下的单词，visit存遍历过的，每到新的一层时，需在wordSet中清除visit，同时清空visit，然后就是level的控制，维护minLevel和当前level  
同时注意遍历的方式，直接从'a'到'z',暴力尝试每一种改变，查询在wordSet中是否存在，再查是否和endWord相等，注意newpaths的运用，在原path上push_back会影响下一次遍历
127. Word Ladder  
可以直接在题126上的基础求解，也就是求minLevel。在存储单词表的时候可以注意一下，从题126换成map的形式，存"*wor"对应的各类string,比如lwor、mwor等。
128. Longest Consecutive Sequence  
最简单的方法是排序后遍历，但是不满足O(n)的时间复杂度要求，可以采用hash的思路，让开空间，就可以直接用一个hashset，不让开空间，就用原数组去存，不断移动当前数到其hash位置处，直到相等或者超出范围
129. Sum Root to Leaf Numbers  
可以选用层历来避免递归，可以选用unordered_map来避免修改原二叉树的值，遇到leaf node加入到结果中即可
130. Surrounded Regions  
二维数组，是否与外界相同，那就将于外界相同的标记一下，然后遍历整个数组，将未标记的置为X，已标记的恢复O即可  
从外界向里遍历，可用bfs，较为方便，也可以采用回溯法
131. Palindrome Partitioning  
依旧是dp的思路，只不过dp的计算比较奇特，由于回文的特殊性，因此从中间进行扩展，并需要考虑奇数回文和偶数回文的区别。且需要从后向前遍历较好，存储的不是int，也相对麻烦  
也可以用dfs去遍历，关键是vector\<string>& path的用法，以及需要写一个isPalindrome判断函数
132. Palindrome Partitioning II  
相对于上题，仅需计算最小切割数，因此用dp求解相对较好，需要考虑的是回文的特殊性
```cpp
for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
    cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
    cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
```
133. Clone Graph  
利用unordered_map来保存原节点和映射节点间的对应关系，然后直接遍历即可，避免重复添加，也即是判断map里是否已有，没有则new一个
134. Gas Station  
部分和的问题，假设i是初始位置，那么i点之后的部分和都会大于等于0，所以i前的部分和一定是最小的，转化为求最小total的问题，可以利用stl降低代码量
135. Candy  
糖果分配问题，最简单好记的是开两个数组，从左遍历和从右遍历，取最大值，可以优化至开一个数组，第二次遍历的时候在原数组上求max即可，另一种方法就是判断斜率，只计算各类山，略复杂
136. Single Number  
异或运算即可
137. Single Number II  
求和的方法比较容易理解: d(非重复元素乘上倍数-原数组和)/(倍数-1)
138. Copy List with Random Pointer  
比较好记的思路是将复制的链表插入到原链表各节点的next处，然后复制random指针，也可以用random指针来暂存复制的节点
139. Word Break  
dfs不满足leetcode时间限制，常规字符串匹配还是用滑动窗口or动态规划来解，此题适宜dp  
对于dp[i]，查0...i间dp[j]==true的，然后切割出来的字符串是否能在给的wordDict数组里找到，可优化，不必遍历0...i，根据wordDict中最长字符串len来降低遍历范围
140. Word Break II  
dp+dfs，先用dp求哪些地方可以匹配，然后按dp出的vector\<bool>进行dfs遍历，注意minLen和maxLen的运用，用于缩小遍历范围。  
另外就是注意题目给的vector\<string>，可以先手动转换为unordered_set
141. Linked List Cycle  
链表找环，快慢指针
142. Linked List Cycle II  
链表找环的入口，公式推导
143. Reorder List  
找中，反转，合并三步
144. Binary Tree Preorder Traversal  
二叉树前序遍历
145. Binary Tree Postorder Traversal  
二叉树后序遍历，如有需要还是用递归做，非递归的关键在于当左右孩子都访问后，才能弹出栈
146. LRU Cache  
使用list来增删，使用unordered_map来查找，map里存key值和其对应的pair<key,list::iterator>，注意到达容量上限时，需删除list和map的back元素
147. Insertion Sort List  
链表插入排序，对于每一个cur，将其插入合适的地方，需每次从头遍历，找合适的插入点，同时需要跳过已排好序的
148. Sort List  
归并排序在链表排序中空间占用降至O(1)，快排的话，关键依旧是partitionList()函数，需要用双指针，遇到小于key值的，做一下交换  
归并排序更好理解，找中，断开，递归（对前半段排序和对后半段进行归并排序），再合并即可
149. Max Points on a Line  
斜率用pair<int,int>来存，double不适合，采用map而不是hashmap来存斜率，因为hashmap底层是hash，需要手动传动hash实例类型，不如map方便  
对每一个点，计算其后与其具有相同斜率的点的数目，第二层循环里，遍历所选点其后的所有点，有三种情况需要考虑overlap、斜率相同，同一竖直线上，可以先比较同一竖直线上和同一斜率的，取较大值，加上重叠的和本身，与result做max比较即可  
所以需要三种考虑，两次比较，两层循环，一个pair来存斜率，一个map来存斜率和对应的点。同时还需要手写GCD函数来求最大公约数，辗转相除法。
150. Evaluate Reverse Polish Notation  
一般操作就是拿栈来存储对应的值，骚操作可以利用stl里的plus\<int>()等四个仿函数，用map存string对应的仿函数，遇到时调用相应的仿函数即可
151. Reverse Words in a String  
关键是空格过滤，利用find\_first\_not\_of和find\_first\_of函数，然后反向+即可
152. Maximum Product Subarray  
从前往后乘，和从后往前乘，同时比较，然后是遇0置1，相当于重启乘法，最大乘积要么从前开始，要么从后开始，不存在刚好只有中间的一段，可考虑首尾是正数负数四种情况，然后对比一下
153. Find Minimum in Rotated Sorted Array  
二分查找即可
154. Find Minimum in Rotated Sorted Array II  
对于可能有重复出现的情况，一般的二分查找容易出问题，当出现nums[mid]==nums[left]&&nums[mid]==nums[right]三值相等的情况，改成暴力遍历去解
155. Min Stack  
剑指offer给的双栈解法，leetcode参考的一个解法是stack中直接存pair，少创建一个stack
160. Intersection of Two Linked Lists  
三次遍历，一次遍历到某链表到末尾，然后交换一下长短链，第二次遍历对齐链表开头，第三次遍历找是否有交叉点即可
162. Find Peak Element  
要求对数复杂度，因此只好采用二分查找
164. Maximum Gap  
要求复杂度为O(n)，因此采用桶排序为佳，我所认为的关键点是bucketIdx的确定，int bucketIdx = (num - mini) / bucketSize;
165. Compare Version Numbers  
开辟一个数组来存version转换后的值，大小为4即可，默认值赋值为0,注意字符串的切割即可
166. Fraction to Recurring Decimal  
通过map来暂存模拟除法中出现过的数字和在结果字符串中的位置，当查找判定为循环的时候，需在该数字第一次出现的位置处insert一个'('；
167. Two Sum II - Input array is sorted  
滑动窗口来解即满足题目要求
168. Excel Sheet Column Title  
关键在%26的时候需要先自减，因为编号从1开始，而不是从0开始，因而先整体偏移1  
169. Majority Element  
比较好记的几种解法：hash求解，排序求解，计数投票选择，基于快排改进
171. Excel Sheet Column Number  
直接求即可
172. Factorial Trailing Zeroes  
简而言之，不断除5就可以了
173. Binary Search Tree Iterator  
类似中序遍历，利用stack暂存遍历过的值，构造时先存储到所有左子树的左子树，取值的时候判断有无右节点，然后类似中序遍历存取即可
179. Largest Number  
排序即可，排序函数的关键是 a + b > b + a ，然后需要排除一下全0的情况
189. Rotate Array  
循环赋值or两次反转
190. Reverse Bits  
利用位移运算符，模拟两次反转
191. Number of 1 Bits  
用flag标志去匹配、与运算n-1，或者说用静态表
198. House Robber  
dp求解即可，从后往前
200. Number of Islands  
简单的方法就是dfs，遇到1后，将其连接的全部置0即可，bfs也行，进阶操作是利用并查集，相对更复杂
202. Happy Number  
常规方法是利用unordered_set检查是否有重复的，进阶操作是 Floyd Cycle detection algorithm，类似链表判断是否有环，利用slow、fast，判断最后slow是否为1即可
204. Count Primes  
常规求质数方法，6的倍数两侧，另一种操作是利用dp来求解，空间复杂度高，但时间上更快
206. Reverse Linked List  
反转链表，相当简单了
207. Course Schedule  
判断图是否有环，bfs相对简单，邻接表，遇入度为0的就可以丢到队列进行处理，然后循环处理降低连接节点的入度即可，最后判断是否有n个入度为0的节点，可以最后遍历，也可以遍历中递减
208. Implement Trie (Prefix Tree)  
字典树的运用，字典树结构 char content、bool isend、int shared(此题不必)、vector<TrieNode*> children,subNode()
209. Minimum Size Subarray Sum  
双指针解即可，i递增，right扩张
210. Course Schedule II  
依旧是bfs，只是不是判断能否成功，而是需要保存一下结果
212. Word Search II  
dfs超时，需要用dfs配合字典树，字典树可以简化为bool is_end和一个容量为26的数组，小技巧是将遍历过的置为' '，而不是新建visit数组，但是回溯完需恢复
215. Kth Largest Element in an Array  
也就是nth_element()
https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/301338/Python-or-tm-215 中文分析  
用小顶堆即可 priority_queue<int, vector\<int>, greater\<int>> pq; 或者用multiset  
小顶堆是保持堆的大小为k，大顶堆就是pop k次  
基于快排的平均时间复杂度是O(n)，最好的选择大概就是快排了，sgi stl里的nth_element用的也是基于快排的改进
217. Contains Duplicate  
排序或者hash
218. The Skyline Problem  
比较好理解的方法之一是利用multiset<pair<int,int>> 来做，默认升序排列，然后利用一个mulitiset\<int> 来存储高度，需要注意的一个点是，左端点存的时候存负数，从而通过正负来区分是左端点还是右端点，左端点进堆，右端点用来移除对应的高度。遍历一波，发现前一个高度发生了变化，说明
这是一个转折点，可以纳入结果数组，同时更新一下当前高度。
221. Maximal Square  
求的是方阵，相对简单，而另一道不求方阵的，是转化为高度来算最大矩形。求最大方阵，dp里用的公式是min+1,而不是max，要注意
226. Invert Binary Tree  
递归最简单，交换即可，非递归的话，基于层历小改即可  
227. Basic Calculator II  
双栈，一个存num，一个存op。遇乘除，计算完再扔进num栈，最后一次遍历的时候算加减即可
230. Kth Smallest Element in a BST  
中序遍历k步即可
234. Palindrome Linked List  
利用递归栈，理解起来比较复杂，考虑递归带来的空间复杂度O(n)，不太适合此题，允许修改链表的话，最好的是链表找中，反转后半部分，然后双指针进行比较
236. Lowest Common Ancestor of a Binary Tree  
递归方法的关键在于设置3个bool变量，left、right、mid变量，如果mid+left+right>=2说明该节点是所需节点  
方法二是利用层历标记一下parent节点，可以用unordered_map来存，循环终止条件是p和q都被放入map了，不需要遍历完所有的节点，然后上溯p的所有父节点，对q上溯，同时查是否出现在p的父节点集合里就可以了
237. Delete Node in a Linked List  
因为给的是要删除的那个节点，因此找不到root节点，没法遍历，可以通过修改当前节点的值为下一节点的值，然后跳过下一节点即可，可以的话，还可以delete一下
238. Product of Array Except Self  
本题限制除法的运用，常规解法就是开个数组先暂存部分和，然后从右向左遍历即可
239. Sliding Window Maximum  
常规方法是利用multiset来解，但时间复杂度不满足题目的线性复杂度要求，第二种方法是维护三个指针，left、right、maxIndex，maxIndex失效时，重新维护一下，复杂度接近线性  
最好的操作是动态规划，利用left和right数组，先按k分好区，然后left是区间内从左到右，取大值，right是区间从右到左取大值，这样，跨区间的就可以从区间分割线向左出发，最大为right[i]，分割线向右出发，最大为left[j]
240. Search a 2D Matrix II  
从左下角开始搜索，逐步逼近，改进思路是二分查找，或stl里的upper_bound，步进可以退出while循环，方便的返回false
242. Valid Anagram  
开26大小的数组即可，然后比较
268. Missing Number  
同样是开一个同大小的数组，然后遍历即可
279. Perfect Squares  
dp算法，dp[i]代表least num，从j=1开始，向前循环遍历求解，dp[i]=min(dp[i],dp[i-j*j]+1);
283. Move Zeroes  
双指针维护一下
287. Find the Duplicate Number  
可以当成链表找环，也可以用求和的方式来做吧，求和需要注意溢出，链表找环，第一步是快慢指针，第二步是将快指针重置为初始位置，速度降为慢指针，走x步，也即是m*n-k步，刚好原慢指针走到环入口
289. Game of Life  
计算周边和，做好标记，再更新即可
295. Find Median from Data Stream  
插入排序可以考虑，two heaps也行，一个max heap，一个min heap，大顶堆用于存较小的值，小顶堆用于存较大的值，因此取中间值即可，然后就是添加步骤，先丢大顶堆，再取大顶堆堆顶进小顶堆，弹出大顶堆堆顶值，依据两个堆的大小，再次平衡一下
297. Serialize and Deserialize Binary Tree  
简单的方法是利用递归，复杂点的是利用层历，要注意层历的终止条件的判断
300. Longest Increasing Subsequence  
LIS问题，动态规划，维护一个类单调栈，用stl里的*lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];可以降低很多代码量  
返回的结果是 return lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin();
```cpp
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    for (int i = 0; i < n; ++i) {
        *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
    }
    return lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin();
}
```
301. Remove Invalid Parentheses  
递归法的经典运用，许多参数的整合，index、left、right计数，终止条件多层if判断，第一次判断是否到结尾处，第二次判断表达式是否有效，即左括号是否等于右括号，第三次
判断移除的左右括号数是否小于等于最小和，因为题目要求移除极可能少的字符使其有效，第四次判断是否小于，小于的话，需要更新，等于的话加入到结果里即可。递归部分，一个添加一个字符，先判断是否'('or')'，不是的话，直接添加，递归下去，递归完需要
恢复，是的话，就有三种情况，直接不考虑当前括号，进行递归，是'('，那么可以丢进去递归，是')'，需要判断当前右括号数量是否小于左括号数量，大于或等于的情况可以省略，即剪枝，当然，最后仍然是恢复现场，毕竟用的是string&
309. Best Time to Buy and Sell Stock with Cooldown  
需要有间隙期的股票交易问题，用的依然是dp，或者说四个变量来控制，比较简单易记的方式是维持三个dp数组，buy、sell和reset，再或者只用buy和sell数组的话，buy[i]与sell[i-2]产生关联
312. Burst Balloons  
可以视作滑动窗口，先计算只有一格的窗口，也就是k=2，然后逐步往上推导，最后返回dp[0][n-1]即可  
可以先用 vector\<int> balloons(nums.size() + 2) 来过滤一下0，重组原数组，使用三重循环，第一层循环k，第二层循环left，第三层循环i至right(即left+k)
315. Count of Smaller Numbers After Self  
看来记的还不错，利用插入排序，从后向前遍历，同时利用lower_bount去查个数
322. Coin Change  
背包问题，动态规划
324. Wiggle Sort II  
大于midian的放靠前的奇数位，小于midian的放靠后的偶数位，解法依旧不太好明白
326. Power of Three  
能循环的话，比较简单，题目要求尽量不用循环或递归，数学上log3(n)=log10(n)/log10(3)，判断结果是不是整数即可
328. Odd Even Linked List  
暴力遍历即可，隔一个连接一下
329. Longest Increasing Path in a Matrix  
dfs，求每个点出发的最长长度，且可复用，在求另一个点时，遍历到此点，不必再往下遍历，直接加上去即可
334. Increasing Triplet Subsequence  
维持三个变量即可，或者一个sub[3]的数组，用LIS问题的简化方法处理
337. House Robber III  
递归求解，引入剪枝，可以用map存已计算好的，遍历到该值时直接返回即可
338. Counting Bits  
找规律问题，就像vector开辟空间一样，以2的指数的形式向上增加，每次复制前面的数，+1即可
341. Flatten Nested List Iterator  
需要一个栈来暂存
344. Reverse String  
直接交换了事
347. Top K Frequent Elements  
朴素方法是map来存，然后反转一下second和first顺序，丢到vector<pair<int,int>> 里排序即可  
因为只需要求top k，因此可以大顶堆或小顶堆来做，大顶堆就是弹出k次，小顶堆就是保持有k个元素
350. Intersection of Two Arrays II  
排序再合并，重点是各种大量数据的情况，延伸开来的问题
371. Sum of Two Integers  
不能使用加法，那么只好用位运算来模拟，先异或，然后通过与运算计算进位，对进位左移，循环进行
378. Kth Smallest Element in a Sorted Matrix  
依旧是二分查找，但是判断的是，在每一行里去求位置，累计后的值和k作比较
380. Insert Delete GetRandom O(1)  
一个vector和一个unordered_map，map存插入的值和其在数组中的位置即可，弹出的操作比较取巧，取数组末尾的值，替换到要删除的值的位置，然后再删除vector末尾的值
384. Shuffle an Array  
洗牌算法，保留一个原数组即可
387. First Unique Character in a String  
hash后，再重新遍历，找第一个hash值为1的即可
394. Decode String  
用栈来存'['的位置以及放大的倍数即可
395. Longest Substring with At Least K Repeating Characters  
可以说是滑动窗口，又比较奇特的滑动窗口，判断l、r区间是否满足要求，不满足的话，就根据区间内出现次数小于k的字符来划分
399. Evaluate Division  
并查集的标准使用，Node节点，然后可以用map来存string对应的节点 
```cpp
struct Node {
    Node* parent;
    double value = 0.0;// 表示当前节点/parent的值，我觉得定为1.0更好，因为自己除自己为1.0
    Node() { parent = this; }
};
``` 
406. Queue Reconstruction by Height  
按h从大到小，k从小到大排，再来根据k值将其插入指定的位置，保证前面比他大的数定下来，后序插入的比其小，不会影响他的结果
412. Fizz Buzz  
判断是否是15、5、3的倍数即可
416. Partition Equal Subset Sum  
依旧是背包问题，只不过和是sum/2，且和为奇数时，可以直接返回false
437. Path Sum III  
类似两重递归即可
438. Find All Anagrams in a String  
字符串匹配，常用滑动窗口
