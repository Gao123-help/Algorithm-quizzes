import math
"""
字符串有三种编辑操作:插入一个英文字符、删除一个英文字符或者替换一个英文字符。
给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
"""
#双指针思路
def oneEditAway(self, first: str, second: str) -> bool:
    len1 = len(first)
    len2 = len(second)
    if first==second or ((len1==0 and len2==1) or (len1==1 and len2==0)):
        return True
    if abs(len1-len2)<=1:
        a=x=0      #a,b,x,y = 0,0,len1-1,len2-1
        b=len1-1
        y=len2-1
        while a<=b and x<=y and first[a]==second[x]:
            a+=1
            x+=1
        while b>=0 and y>=0 and first[b]==second[y]:
            b-=1
            y-=1
        if len1>len2:
            return a==b
        else:
            return x==y
    return False


#官方题解 更简洁
def oneEditAway(self, first: str, second: str) -> bool:
        m, n = len(first), len(second)
        if m < n:
            return self.oneEditAway(second, first)
        if m - n > 1:
            return False
        for i, (x, y) in enumerate(zip(first, second)):
            if x != y:
                return first[i + 1:] == second[i + 1:] if m == n else first[i + 1:] == second[i:]  # 注：改用下标枚举可达到 O(1) 空间复杂度
        return True
    

