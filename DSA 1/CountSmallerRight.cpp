#include<iostream>
#include<vector>
#include "CountSmallerRight.h"

void merge (std::vector<std::pair<int, int>>& nums, size_t start, size_t mid, size_t end, std::vector<std::pair<int, int>>& temp, std::vector<int>& counts)
{
    int i = start;
    int j = mid + 1;
    int iter = start;
    int rightCount = 0;

    for (size_t t = start; t <= end; t++)
        temp[t] = nums[t];

    while(i <= mid && j <= end)
    {
        if(temp[i].first <= temp[j].first)
        {
            counts[temp[i].second] += rightCount;
            nums[iter++] = temp[i++];
        }
        else
        {
            rightCount++;
            nums[iter++] = temp[j++];
        }
    }

    while(i <= mid)
    {
        counts[temp[i].second] += rightCount;
        nums[iter++] = temp[i++];
    }

    while(j <= end)
        nums[iter++] = temp[j++];
}

void split (std::vector<std::pair<int, int>>& nums, size_t start, size_t end, std::vector<std::pair<int, int>>& temp, std::vector<int>& counts)
{
    if(start >= end)
        return;
    int mid = start + (end - start) / 2;
    split(nums, start, mid, temp, counts);
    split(nums, mid + 1, end, temp, counts);
    merge(nums, start, mid, end, temp, counts);
}


std::vector<int> countSmaller(std::vector<int>& nums) 
{
    std::vector<std::pair<int, int>> pNums;
    std::vector<std::pair<int, int>> temp(nums.size());
    std::vector<int> counts(nums.size(), 0);

    for (size_t i = 0; i < nums.size(); i++)
        pNums.push_back({nums[i], i});
    
    split(pNums, 0, nums.size() - 1, temp, counts);
    return counts;
}
