"""
输入一个三角形的三条边长，判断该三角形是等边三角形、等腰三角形还是普通三角形，并输出相应的提示信息。

具体要求：

    如果输入的三个边长都相等，则判断为等边三角形。
    如果输入的三个边长中有两个边长相等，则判断为等腰三角形。
    如果输入的三个边长都不相等，则判断为普通三角形。
"""

num_list =[int(input(f"请输入第{i+1}条边长：")) for i in range(3)]
if num_list[0]==num_list[1]==num_list[2] :
    print("此三角形是等边三角形")
elif num_list[0]==num_list[1] or num_list[0]==num_list[2] or num_list[1]==num_list[2]:
    print("此三角形是等腰三角形")
else:
    print("是普通三角形")
