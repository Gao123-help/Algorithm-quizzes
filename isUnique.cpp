/*
*实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace  std;

bool isUnique(string astr) {
    unordered_map<char,int>map;
    for(int i=0;i<astr.size();i++)
    {
        auto it = map.find(astr[i]);
        if (it!=map.end())
        {
            return false;
        } 
        map[astr[i]]=i;
    }
    return false;

}

