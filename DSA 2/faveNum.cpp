#include "faveNum.h"


size_t Power(size_t base, size_t exponent)
{
    size_t result = 1;

    for (size_t i = 0; i < exponent; i++)
        result *= base;

    return result;
}

void FaveNum(std::vector<size_t>& friendNums, size_t left, size_t right, size_t depth, size_t& curr)
{
    if (right - left <= 1) 
    {
        if (curr < friendNums.size() && friendNums[curr] == left)
        {
            curr++;
            std::cout << depth ;
        }
        return;
    }

    size_t groupSize = (right - left) / 3;
    size_t mid1 = left + groupSize;
    size_t mid2 = mid1 + 1 + groupSize;
    

    FaveNum(friendNums, left, mid1, depth + 1, curr);

    for (size_t i = mid1 + 1; i <= mid2; i++)
    {
        if(curr < friendNums.size() && friendNums[curr] == i + 1)
        {
            curr++;
            std::cout << depth;
        }
    }

    FaveNum(friendNums, mid2 + 1, right, depth + 1, curr);
}

void Input()
{
    auto subGroupCount = 3;
    auto initDepth = 1;
    size_t N, P;

    std::cin >> P >> N;

    std::vector<size_t> friends(N);

    for (size_t i = 0; i < N; i++)
        std::cin >> friends[i];

    auto size = Power(subGroupCount, P);
    size_t curr = 0;

    FaveNum(friends, 0, size - 1, initDepth, curr);

}