#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
/*
字符串有三种编辑操作:插入一个英文字符、删除一个英文字符或者替换一个英文字符。
给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
*/
// 双指针
bool oneEditAway(string first, string second)
{
    int len1 = first.size();
    int len2 = second.size();
    if ((first == second) || ((len1 == 0 && len2 == 1) || (len1 == 1 && len2 == 0)))
        return true;
    if (abs(len1 - len2) <= 1)
    {
        int a = 0, b = len1 - 1;
        int x = 0, y = len2 - 1;
        while (a <= b && a <= y && first[a] == second[b])
        {
            a++;
            x++;
        }
        while (b >= 0 && y >= 0 && first[b] == second[y])
        {
            b--;
            y--;
        }
        if (len1 > len2)
            return a == b;
        else
            return x == y;
    }
    return false;
}

// 官方题解，写法更优雅
bool oneEditAway(string first, string second)
{
    int m = first.size(), n = second.size();
    if (n - m == 1)
    {
        return oneInsert(first, second);
    }
    else if (m - n == 1)
    {
        return oneInsert(second, first);
    }
    else if (m == n)
    {
        bool foundDifference = false;
        for (int i = 0; i < m; i++)
        {
            if (first[i] != second[i])
            {
                if (!foundDifference)
                {
                    foundDifference = true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool oneInsert(string shorter, string longer)
{
    int length1 = shorter.size(), length2 = longer.size();
    int index1 = 0, index2 = 0;
    while (index1 < length1 && index2 < length2)
    {
        if (shorter[index1] == longer[index2])
        {
            index1++;
        }
        index2++;
        if (index2 - index1 > 1)
        {
            return false;
        }
    }
    return true;
}
