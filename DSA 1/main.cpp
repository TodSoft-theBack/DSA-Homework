#include<iostream>
#include<vector>
#include "utils.hpp"
#include "mergeIntervals.h"


int main()
{
    std::vector<std::vector<int>> intervals = {{4,6}, {8,9}, {6,7}, {1,4}};
    auto merged = merge(intervals);
    PrintArray(merged);
    return 0;
}