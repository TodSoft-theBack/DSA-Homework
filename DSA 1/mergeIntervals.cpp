
#include <iostream>
#include <vector>
#include <algorithm>
#include "mergeIntervals.h"

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) 
{
    std::vector<std::vector<int>> result;
    std::sort
    (
        intervals.begin(),
        intervals.end(),
        [](const std::vector<int>& a, const std::vector<int>& b)
        {
            return a[0] < b[0];
        }
    );

    std::vector<int> prev = intervals[0];
    for (size_t i = 1; i < intervals.size(); i++)
    {
        if (prev[1] >= intervals[i][0])
        {
            if (prev[1] < intervals[i][1])
                prev[1] = intervals[i][1];
        }
        else
        {
            result.push_back(prev);
            prev = intervals[i];
        }
        
    }

    result.push_back(prev);

    return result;
    
}