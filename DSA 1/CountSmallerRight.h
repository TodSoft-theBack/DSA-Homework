#include<iostream>
#include<vector>
#pragma once

void merge 
(
    std::vector<std::pair<int, int>>& nums, 
    size_t start, 
    size_t mid, 
    size_t end, 
    std::vector<std::pair<int, int>>& temp, 
    std::vector<int>& counts
);

void split 
(
    std::vector<std::pair<int, int>>& nums, 
    size_t start, 
    size_t end, 
    std::vector<std::pair<int, int>>& temp, 
    std::vector<int>& counts
);

std::vector<int> countSmaller(std::vector<int>& nums);
