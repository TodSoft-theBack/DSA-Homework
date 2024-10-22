#include <unordered_map>
#include <cmath>
#include <iostream>
#include <vector>
#include "diplicateWithinDistanceK.h"

bool DiplicateWithinDistance::containsNearbyDuplicate(std::vector<int>& nums, int k)
{
        std::unordered_map<int, int> setOfValues;
        setOfValues[nums[0]] = 0;
        for(int i = 1; i < nums.size(); i++)
        {

            if (setOfValues.find(nums[i]) == setOfValues.end())
                setOfValues[nums[i]] = i;
                
            if
            (
                i != setOfValues[nums[i]] &&
                std::abs(i - setOfValues[nums[i]]) <= k
            )
                return true;

            setOfValues[nums[i]] = i;
        }
        return false;
    }
