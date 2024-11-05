#include<iostream>
#include<vector>
#pragma once

template<typename T>
void PrintArray(const T* arr, size_t len, bool skipNewLine = false)
{
    std::cout << "[ ";
    for (size_t i = 0; i < len; i++)
    {
        std::cout << arr[i];
        if(i < len - 1)
            std::cout << ", ";
    }
    std::cout << " ]";
    if (!skipNewLine)
        std::cout << std::endl;
}

template<typename T>
void PrintArray(const T* const* arr, size_t len, bool skipNewLine = true)
{
    std::cout << "[ ";
    for (size_t i = 0; i < len; i++)
    {
        PrintArray(arr[i], true);
        if(i < len - 1)
            std::cout << ", ";

        if (!skipNewLine)
            std::cout << std::endl;
    }
    std::cout << " ]" << std::endl;
}

template<typename T>
void PrintArray(const std::vector<T>& arr, bool skipNewLine = false)
{
    std::cout << "[ ";
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
        if(i < arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << " ]";
    if (!skipNewLine)
        std::cout << std::endl;
    
}

template<typename T>
void PrintArray(const std::vector<std::vector<T>>& arr, bool skipNewLine = true)
{
    std::cout << "[ ";
    for (size_t i = 0; i < arr.size(); i++)
    {
        PrintArray(arr[i], true);
        if(i < arr.size() - 1)
            std::cout << ", ";

        if (!skipNewLine)
            std::cout << std::endl;
    }
    std::cout << " ]" << std::endl;
}