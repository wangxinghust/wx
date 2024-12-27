class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        sub_string_set = set()
        for i in range(len(s) - 1):
            sub_string_set.add(s[i:i + 2])
        for i in range(len(s) - 1, 0, -1):
            reverse_sub_string = s[i] + s[i - 1]
            if reverse_sub_string in sub_string_set:
                return True
        return False
    
class SolutionV2:
    """方法一: 一次遍历
    """
    def isSubstringPresent(self, s: str) -> bool:
        for i in range(len(s) - 1):
            if s[i:i+2][::-1] in s:
                return True
        return False

class SolutionV2:
    """方法一: 一次遍历
    """
    def isSubstringPresent(self, s: str) -> bool:
        for i in range(len(s) - 1):
            if s[i:i+2][::-1] in s[:i]:
                return True
        return False

class SolutionV3:
    """方法二：哈希表 + 位运算优化
    哈希表是一个关键
    另一个关键是一次遍历即可, 只需要在已遍历的子串中查找是否反转的存在即可。在方法一种没有体现
    """
    def isSubstringPresent(self, s: str) -> bool:
        h = [0] * 26
        for i in range(len(s) - 1):
            x = ord(s[i]) - ord('a')
            y = ord(s[i + 1]) - ord('a')
            h[x] |= 1 << y
            if h[y] >> x & 1:
                return True
        return False