/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int,int>map;
  vector<int>ret;
  for (int i = 0; i < nums.size(); i++)
  {
    auto it = map.find(target-nums[i]);
    if (it != map.end())
    {
        ret.push_back(i);
        ret.push_back(it->second);
        break;
    }
    //*将元素放入字典的操作放在后面是为了防止查找哈希的时候算上自己
    map[nums[i]]=i;
  } 
  return ret;  
}
