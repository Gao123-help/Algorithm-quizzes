import collections
#from types import lists
#哈希
def isUnique(self, astr: str) -> bool:
    dic = collections.defaultdict(int)
    for i in astr:
        if i in dic:
            return False
        dic[i]+=1
    return True

#方法二：位运算
def isUnique1(self, astr: str) -> bool:
    mark = 0
    for char in astr:
      move_bit = ord(char) - ord('a')
      if (mark & (1 << move_bit)) != 0:
        return False
      else:
        mark |= (1 << move_bit)
    return True

str1 = "adcda"
print(isUnique1(1,str1))
